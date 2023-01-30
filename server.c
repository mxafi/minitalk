/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:11:25 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/30 20:46:49 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %i\n", server_pid);
	pause();
	return (0);
}
