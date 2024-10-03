#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	len;

	len = ft_strlen(str) + 1;
	str2 = (char *)malloc(len);
	if (!str2)
		return (NULL);
	ft_memcpy(str2, str, len);
	return (str2);
}
