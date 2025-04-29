/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:41:03 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/29 10:06:51 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endpoint.h"

t_endpoint	ft_init_endpoint(char **args)
{
	char	*ip;
	int		port;
    int     index;
    bool    flag;

    flag = false;
    index = 0;
    if (!ft_strncmp(args[0], "-v", 3))
    {
        flag = true;
        index = 1;
    }
	ip = ft_strdup(args[index]);
	port = 0;
    index++;
	if (args[index])
		port = atoi(args[index]);
	ft_free_tab(args);
	return ((t_endpoint){.ip = ip, .port = port, .flag = flag});
}

void	ft_free_endpoint(t_endpoint *endpoint)
{
	if (endpoint->ip)
		free(endpoint->ip);
}

void	print_flag(t_endpoint endpoint)
{
	ft_printf("ping: sock4.fd: 3 (socktype: SOCK_RAW), sock6.fd: 4 (socktype: SOCK_RAW), hints.ai_family: AF_INET\n\n");
	ft_printf("ai->ai_family: AF_INET, ai->ai_canonname: '%s'\n", endpoint.ip);
}

unsigned short	checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char*)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}
