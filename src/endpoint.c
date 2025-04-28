/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:41:03 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/24 13:12:39 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endpoint.h"

t_endpoint	ft_init_endpoint(char **args)
{
	char	*ip;
	int		port;

	ip = ft_strdup(args[0]);
	port = 0;
	if (args[1])
		port = atoi(args[1]);
	ft_free_tab(args);
	return ((t_endpoint){.ip = ip, .port = port});
}

void	ft_free_endpoint(t_endpoint *endpoint)
{
	if (endpoint->ip)
		free(endpoint->ip);
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
