/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:45:03 by fech-cha          #+#    #+#             */
/*   Updated: 2022/02/10 16:33:52 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

int	g_pid = 0;

void	handle_sigusr(int sign, siginfo_t *sig_info, void *ign)
{
	static char	ascii;
	static int	index;

	(void)ign;
	if (g_pid != sig_info->si_pid)
	{
		ascii = 0;
		index = 0;
		g_pid = sig_info->si_pid;
	}
	if (sign == SIGUSR1)
		ascii = ascii << 1 | 1;
	else if (sign == SIGUSR2)
		ascii = ascii << 1 | 0;
	index++;
	if (index == 8)
	{
		write(1, &ascii, 1);
		ascii = 0;
		index = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%sPID = %d\n", KMAG, pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(100);
	return (0);
}
