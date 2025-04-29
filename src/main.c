/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:33:14 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/29 10:06:38 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_exit(char *msg, int error)
{
	ft_printf("%s%s%s\n", BG_RED, msg, RESET);
	exit(error);
}

int	main(int argc, char **argv)
{
	t_endpoint endpoint;

	endpoint = ft_init_endpoint(ft_read_args(argc, argv));
	if (endpoint.flag)
		print_flag(endpoint);
	init_socket(endpoint.ip);
	ft_free_endpoint(&endpoint);
	return (0);
}
