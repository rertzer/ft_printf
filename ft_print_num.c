/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:30:06 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 10:50:47 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(t_data *data)
{
	return (print_str_and_free(ft_itoa(va_arg(data->ap, int))));
}

int	ft_print_uns(t_data *data)
{
	return (print_str_and_free(ft_uxitoa(va_arg(data->ap, unsigned int), BASETEN)));
}

int	ft_print_lhx(t_data *data)
{
	return (print_str_and_free(ft_uxitoa(va_arg(data->ap, unsigned int), BASELHEX)));
}

int	ft_print_uhx(t_data *data)
{
	return (print_str_and_free(ft_uxitoa(va_arg(data->ap, unsigned int), BASEUHEX)));
}

int	ft_print_point(t_data *data)
{
	t_ull	p;

	p = va_arg(data->ap, t_ull);
	if (p)
		return (print_str_and_free(ft_pointoa(p)));
	write(1, "(nil)", 5);
	return (5);
}
