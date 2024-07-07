/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:25:37 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 02:09:44 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int num, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (num < 0)
	{
		num = -num;
		*len += write(1, "-", 1);
	}
	if (num >= base)
		put_digit((num / base), base, len);
	*len += write(1, &hexa[num % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	pointer;

	len = 0;
	va_start(pointer, format);
	while (*format)
	{
		if ((*format == '%') && ((*format + 1) == 's' || *(format + 1) == 'd'
				|| *(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16,
					&len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), len);
}
