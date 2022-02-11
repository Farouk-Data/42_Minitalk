/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:39:16 by fech-cha          #+#    #+#             */
/*   Updated: 2022/02/10 17:40:16 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# define KMAG  "\x1B[35m"
# define KGRN  "\x1B[32m"
# define KCYN  "\x1B[36m"

char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_send_bit(char c, pid_t pid);
int		check_pid(pid_t pid, char *str);
void	handle_sigusr(int sign, siginfo_t *sig_info, void *ign);
void	signal_back_handler(int signum);

#endif
