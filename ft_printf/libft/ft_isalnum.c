#include "libft.h"

int	ft_isalnum(int ch)
{
	int	alpha;
	int	digit;

	alpha = ft_isalpha(ch);
	digit = ft_isdigit(ch);
	if (alpha == 1 || digit == 1)
		return (1);
	else
		return (0);
}
