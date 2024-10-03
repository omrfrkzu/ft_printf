#include "libft.h"

char	*ft_strchr(const char *src, int a)
{
	while (*src != 0 && (char)a != *src)
		src++;
	if ((char)a == *src)
		return ((char *)src);
	return (0);
}
