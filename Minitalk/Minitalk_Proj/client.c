/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:44:16 by fech-cha          #+#    #+#             */
/*   Updated: 2022/02/08 07:44:32 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

void send_bit(char c, pid_t pid)
{
    int bit;
    int shift;

    bit = 8;
    shift = 0;
    while (bit)
    {
        if ((c & 128 >> shift))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        bit--;
        shift++;
    }
}

int main(int argc, char **argv)
{
    char *string;
    int len;
    pid_t pid;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        string = ft_strdup(argv[2]);
        len = ft_strlen(string);  
        while (len)
        {
            send_bit(*string,pid);
            string++;
            len--;
        }
    }
    else
        ft_printf("Not enough arguments\n");
}