#include "ft_printf.h"

static int	ft_print_address(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_address(n / 16);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	address = (unsigned long)ptr;
	count = ft_print_str("0x");
	count += ft_print_address(address);
	return (count);
}
