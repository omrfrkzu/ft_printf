#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t a)
{
	size_t	i;

	i = 0;
	while (i < a)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == '\0' && *str2 == '\0')
			return (0);
		i++;
		str1++;
		str2++;
	}
	return (0);
}