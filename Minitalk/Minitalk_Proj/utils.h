#ifndef UTILS_H 
#define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#define KMAG  "\x1B[35m"
#define KGRN  "\x1B[32m"
#define KCYN  "\x1B[36m"

char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int	ft_atoi(const char *str);
int ft_strlen(char *str);
void send_bit(char c, pid_t pid);

#endif