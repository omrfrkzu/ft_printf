#include "libft.h"

void	*ft_memcpy(void *b, const void *a, size_t len)
{
	size_t	i;

	if (len == 0 || b == a)
		return (b);
	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = ((unsigned char *) a)[i];
		i++;
	}
	return (b);
}
