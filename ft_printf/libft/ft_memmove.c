#include "libft.h"

void	*ft_memmove(void *dest, const void *sour, size_t len)
{
	if (dest == 0 && sour == 0)
		return (0);
	if (dest < sour)
		ft_memcpy(dest, sour, len);
	else if (dest > sour)
	{
		while (len--)
			*((unsigned char *)(dest + len)) = *((unsigned char *)(sour + len));
	}
	return (dest);
}
