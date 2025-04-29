/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:54:31 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/29 09:45:27 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**ft_read_args(int argc, char **argv)
{
	char 		**tab;
	char		*str;
	char		*tmp;
	int			i;

	i = 0;
	str = ft_strdup("");
	if (argc < 2)
		ft_exit(E_ARG, -1);
	while (argv[++i])
	{
		tmp = str;
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		free(tmp);
	}
	tab = ft_split(str, ' ');
	free(str);
	if (!tab || !tab[0])
	{
		ft_free_tab(tab);
		ft_exit(E_ARG, -1);
	}
	return (tab);
}

