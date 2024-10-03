#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	len = ft_strlen(dst);
	i = len;
	if (size <= len)
		return (size + ft_strlen(src));
	while (src[len - i] && len + 1 < size)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < size)
	{
		dst[len] = '\0';
	}
	return (i + ft_strlen(src));
}
