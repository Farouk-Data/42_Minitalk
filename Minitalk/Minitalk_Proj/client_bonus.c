/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:30:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/02/14 17:29:45 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

int	check_pid(pid_t pid, char *str)
{
	if (pid < 1 || ft_strlen(str) > 5)
		return (0);
	else
		return (1);
}

void	ft_send_bit(char c, pid_t pid)
{
	int	bit;
	int	shift;

	bit = 8;
	shift = 0;
	while (bit)
	{
		if ((c & 128 >> shift))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit--;
		shift++;
	}
}

void	signal_back_handler(int signum)
{
	signum++;
	write(1, KGRN"RECEIVED\n", 15);
}

int	main(int argc, char **argv)
{
	int		len;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		len = ft_strlen(argv[2]) + 1;
		if (!check_pid(pid, argv[1]))
		{
			ft_printf("Invalid PID!\n");
			exit(1);
		}
		else
		{
			signal(SIGUSR1, signal_back_handler);
			while (len)
			{
				ft_send_bit(*argv[2], pid);
				argv[2]++;
				len--;
			}
		}
	}
	else
		ft_printf("Not enough arguments\n");
}
