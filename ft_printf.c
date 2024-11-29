/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:43 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/29 20:10:43 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_printnbr_base(long int nb, char *base, int base_size)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += (int)write(1, "-", 1);
		nb = -nb;
	}
	if (nb > base_size - 1)
	{
		len += (int)ft_printnbr_base(nb / base_size, base, base_size);
	}
	len += (int)ft_printchar(base[nb % base_size]);
	return (len);
}


int	sort_format(const char format, va_list args)
{
	int	len;
	long int p;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	if (format == 'p')
	{
		p = va_arg(args, long int);
		if (p == 0)
		{
			len += write(1, "(nil)", 5);
			return (len);
		}
		else
		{
			len += ft_printstr("0x");
			len += ft_printnbr_base(p, "0123456789abcdef", 16);
		}
	}
	if ((format == 'd') || (format == 'i'))
		len += ft_printnbr_base(va_arg(args, int), "0123456789", 10);
	if (format == 'u')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789", 10);
	if (format == 'x')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				16);
	if (format == 'X')
		len += ft_printnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				16);
	if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return(0);
			len += sort_format(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
// int	main(void)
// {
// 	ft_printf("%p\n",LONG_MIN);
// 	printf("%p", LONG_MIN);
// }