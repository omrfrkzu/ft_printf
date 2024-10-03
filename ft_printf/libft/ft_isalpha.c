#include "libft.h"

int	ft_isalpha(int str)
{
	if ((str >= 65 && str <= 90) || (str >= 97 && str <= 122))
		return (1);
	else
		return (0);
}
