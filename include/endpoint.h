/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endpoint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:41:37 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/29 10:15:12 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDPOINT_H
# define ENDPOINT_H

# include "include.h"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <errno.h>
# include <netdb.h>
# include <sys/time.h>
# include <stdbool.h>
# include <signal.h>

typedef struct s_endpoint {
	char	*ip;
	bool	flag;
	int		port;
} t_endpoint;

struct icmp_packet {
	struct icmphdr hdr;
	char payload[56];
};

unsigned short	checksum(void *b, int len);
t_endpoint		ft_init_endpoint(char **args);
char			*resolve_hostname(char *hostname);
void			ft_free_endpoint(t_endpoint *endpoint);
void			init_socket(char *target);
void			receive_packet(int sockfd);
void			print_statistic(char *target);
void			send_packet(int sockfd, struct sockaddr_in dest_addr, int seq);
void			print_flag(t_endpoint endpoint);

#endif
