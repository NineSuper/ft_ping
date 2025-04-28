/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:31 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/23 13:56:07 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**ft_read_args(int argc, char **argv)
{
	t_endpoint	endpoint;
	char 		**tab;

	if (argc != 2)
		ft_exit(E_ARG, -1);
	tab = ft_split(argv[1], ':');
	if (!tab || !tab[0])
	{
		ft_free_tab(tab);
		ft_exit(E_ARG, -1);
	}
	return (tab);
}
