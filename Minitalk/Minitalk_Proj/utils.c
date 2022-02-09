#include "utils.h"

int ft_strlen(char *str)
{
    int count ;

    count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return (count);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	char	*new_src;

	i = 0;
	new_src = (char *)src;
	if (size > 0)
	{
		while (i < size - 1 && new_src[i])
		{
			dst[i] = new_src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	char	*ptr;
	size_t	len;

	new_s = (char *)s;
	len = ft_strlen(new_s) + 1;
	ptr = (char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, new_s, len + 2);
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}