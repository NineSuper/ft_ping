/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:55:02 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/25 09:32:10 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

volatile sig_atomic_t running = 1;
int sent_count = 0;
int received_count = 0;

void	handle_sigint(int sig)
{
	(void)sig;
	running = 0;
}

char	*resolve_hostname(char *hostname)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in *addr;
	char				ip[INET_ADDRSTRLEN];

	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(hostname, NULL, &hints, &res) != 0)
		return (NULL);
	addr = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip));
	freeaddrinfo(res);
	return (ft_strdup(ip));
}

void	send_packet(int sockfd, struct sockaddr_in dest_addr, int seq)
{
	struct icmp_packet	packet;
	struct timeval		start;

	gettimeofday(&start, NULL);
	ft_bzero(&packet, sizeof(packet));
	packet.hdr.type = ICMP_ECHO;
	packet.hdr.code = 0;
	packet.hdr.un.echo.id = getpid() & 0xFFFF;
	packet.hdr.un.echo.sequence = seq;
	ft_strlcpy(packet.payload, "Hello World!", sizeof(packet.payload));
	packet.hdr.checksum = checksum(&packet, sizeof(packet));
	if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) >= 0)
		sent_count++;
}

void	init_socket(char *target)
{
	struct sockaddr_in	dest_addr;
	char				*ip;
	int					sockfd;
	int					seq = 1;
	struct timeval		timeout;

	signal(SIGINT, handle_sigint);
	ip = resolve_hostname(target);
	if (!ip)
	{
		ft_printf("ping: %s: Name or service not known\n", target);
		return;
	}
	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		perror("socket");
		free(ip);
		return;
	}
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
	{
		perror("setsockopt");
		close(sockfd);
		free(ip);
		return;
	}
	ft_bzero(&dest_addr, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &dest_addr.sin_addr);
	ft_printf("PING %s (%s): 64 data bytes\n", target, ip);
	free(ip);
	while (running)
	{
		send_packet(sockfd, dest_addr, seq);
		receive_packet(sockfd);
		seq++;
		sleep(1);
	}
	close(sockfd);
	ft_printf("\n--- %s ping statistics ---\n", PING_STAT, target);
	printf("%d packets transmitted, %d received, %.0f%% packet loss\n",
		sent_count, received_count,
		(sent_count - received_count) * 100.0 / (sent_count ? sent_count : 1));
}

void	receive_packet(int sockfd)
{
	struct timeval	start, end;
	struct iphdr 	*ip;
	char 			buffer[1024];
	double 			elapsed;
	ssize_t 		recv_bytes;

	gettimeofday(&start, NULL);
	recv_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
	gettimeofday(&end, NULL);
	if (recv_bytes > 0)
	{
		ip = (struct iphdr *)buffer;
		elapsed = (end.tv_sec - start.tv_sec) * 1000.0 +
						(end.tv_usec - start.tv_usec) / 1000.0;
		received_count++;
		printf("%ld bytes from ...: icmp_seq=%d time=%.2f ms\n", recv_bytes, received_count, elapsed);
	}
}
