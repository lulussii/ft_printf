/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:18:48 by lserodon          #+#    #+#             */
/*   Updated: 2024/11/29 17:59:21 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return(i);
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
	int len;
	
	len = 0;
	if (nb < 0)
	{
		len += (int) write(1, "-", 1);
		nb = -nb;
	}
	if (nb > base_size - 1)
	{
		len += (int) ft_printnbr_base(nb / base_size, base, base_size);
	}
	len += (int) ft_printchar(base[nb % base_size]);
	return (len);
}