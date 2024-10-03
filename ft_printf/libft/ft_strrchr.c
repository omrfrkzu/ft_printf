#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if (*(str + i) == (char)a)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
