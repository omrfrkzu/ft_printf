#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(num * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, num * size);
	return (buffer);
}
