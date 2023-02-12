/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:11:15 by malaakso          #+#    #+#             */
/*   Updated: 2023/02/12 17:20:51 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			usleep (100);
			kill (pid, SIGUSR2);
		}
		else
		{
			usleep (100);
			kill (pid, SIGUSR1);
		}
		i++;
	}
}

static void	sender(pid_t pid, char *message)
{
	int	message_len;
	int	i;

	message_len = ft_strlen(message);
	i = 0;
	while (i < message_len)
	{
		send_char(pid, message[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message_string;

	if (ac != 3)
	{
		ft_printf("Wrong argument count.\nUsage: ./client <PID> <string>\n");
		exit (1);
	}
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0) != 0)
	{
		ft_printf("Invalid server PID.\nUsage: ./client <PID> <string>\n");
		exit (1);
	}
	message_string = av[2];
	if (av[2][0] == '\0')
	{
		ft_printf("Empty string is not valid.\nUsage: ./client <PID> <string>\n");
		exit (1);
	}
	ft_printf("Sending message...\n");
	sender(server_pid, message_string);
	ft_printf("Message sent.\n");
	return (0);
}
