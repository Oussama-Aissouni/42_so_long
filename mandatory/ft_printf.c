/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:21:14 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/12 14:21:16 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	get_digits(long n, char *base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	i = 1;
	while (n / base_len > 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

static int	ft_putbasedec(int nbr, char	*base)
{
	int		base_count;
	long	i;
	int		digits;

	i = nbr;
	digits = 0;
	base_count = ft_strlen(base);
	if (nbr < 0)
	{
		i *= -1;
		ft_putchar('-');
		digits += 1;
	}
	if ((i / base_count) != 0)
		ft_putbasedec(i / base_count, base);
	ft_putchar(base[i % base_count]);
	digits += get_digits(i, "0123456789");
	return (digits);
}

static int	check(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'd')
		count += ft_putbasedec(va_arg(args, int), "0123456789");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += check(format, i, args);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			count += 1;
			i++;
		}
	}
	va_end(args);
	return (count);
}
