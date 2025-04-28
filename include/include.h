/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:47:42 by tde-los-          #+#    #+#             */
/*   Updated: 2025/04/28 12:02:18 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdbool.h>

# include "libft.h"
# include "ft_printf.h"
# include "endpoint.h"


/*	COLOR	*/
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
/*	Gras	*/
#define B_RED     "\033[1;31m"
#define B_GREEN   "\033[1;32m"
#define B_YELLOW  "\033[1;33m"
#define B_BLUE    "\033[1;34m"
#define B_MAGENTA "\033[1;35m"
#define B_CYAN    "\033[1;36m"
#define B_WHITE   "\033[1;37m"
/*	Background	*/
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"
/*	ERROR	*/
# define E_ARG "./ft_ping <ip:port>/<google.com>"
# define E_IP_INV "Adresse IP invalide"
# define E_SOCKET "Lancez le programme en sudo !"
# define E_IMCP "Erreur lors de l'envoi ICMP"
/*	MESSAGE	*/
# define SOCKET_OK "Socket créé avec succès, prêt à envoyer vers "
# define ICMP_SEND "Paquet ICMP Echo envoyé !"
# define PING_NOT_KNOWN "Name or service not known"

char			**ft_read_args(int argc, char **argv);
void			ft_exit(char *msg, int error);

#endif
