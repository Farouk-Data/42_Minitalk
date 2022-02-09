/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:45:03 by fech-cha          #+#    #+#             */
/*   Updated: 2022/02/08 07:45:06 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

void    handle_sigusr(int sign, siginfo_t *sig_info, void *ign)
{
    (void)ign;
    static char ascii ;
    static int index ;
    static int  p_id ;

    p_id = -1;
    if (p_id != sig_info->si_pid && sig_info->si_pid != 0)
    {
        ascii = 0;
        index = 0;
        p_id = sig_info->si_pid;
    }
    if (sign == SIGUSR1)
        ascii = ascii << 1 | 1;
    else if (sign == SIGUSR2)
        ascii = ascii << 1 | 0;
    index++;
    if (index == 8)
    {
        write(1,&ascii,1);
        ascii = 0;
        index = 0;
    }
    kill(p_id, SIGUSR1);
}

int main()
{
    pid_t pid;
    struct sigaction sa;

    sa.sa_sigaction = &handle_sigusr;
    sa.sa_flags = SA_SIGINFO;
    pid = getpid();
    ft_printf("%sPID = %d\n",KMAG,pid);
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    while(1)
        pause();
    return (0);
}
