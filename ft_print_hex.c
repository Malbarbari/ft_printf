#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*base;
	int		count;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, format);
	count += ft_print_char(base[n % 16]);
	return (count);
}
