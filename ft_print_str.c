#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		count += ft_print_char(*str);
		str++;
	}
	return (count);
}
