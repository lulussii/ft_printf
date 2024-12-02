/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:26:26 by lserodon          #+#    #+#             */
/*   Updated: 2024/12/02 15:17:03 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printf(const char *format, ...);
int	ft_printnbr_base(long int nb, char *base, int base_size);
int ft_printbr_p(unsigned long int, char *base, unsigned long int base_size);
int	sort_format(const char format, va_list args);

#endif