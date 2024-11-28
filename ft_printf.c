/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:35:43 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/28 17:56:56 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Rank_00/libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (0);
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
	return (0);
}

int	ft_printnbr_base(long int nb, char *base, int base_size)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_printnbr_base(nb / base_size, base, base_size);
	}
	ft_printchar(base[nb % base_size]);
	return(0);
}

static int	sort_format(const char format, va_list args)
{
	if (format == 'c')
		ft_printchar(va_arg(args, int));
	if (format == 's')
		ft_printstr(va_arg(args, char *));
	if (format == 'p')
		ft_printaddress(va_arg(args, char *));
	if ((format == 'd') || (format == 'i'))
		ft_printnbr_base(va_arg(args, int), "0123456789", 10);
	if (format == 'u')
		ft_printnbr_base(va_arg(args, long int), "0123456789", 10);
	if (format == 'x')
		ft_printnbr_base(va_arg(args, int), "0123456789abcdef", 16);
	if (format == 'X')
		ft_printnbr_base(va_arg(args, int), "0123456789ABCDEF", 16);
	if (format == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			sort_format(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (0);
}
int	main(void)
{
	ft_printf("hello %%");
	printf("hello %%");
}