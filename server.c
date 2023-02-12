/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:11:25 by malaakso          #+#    #+#             */
/*   Updated: 2023/02/12 20:00:38 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	got_data(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
		c = 0x00;
	}
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	signal(SIGUSR1, got_data);
	signal(SIGUSR2, got_data);
	ft_printf("Server PID: %i\n", server_pid);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
