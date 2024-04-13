/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:07:58 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 11:59:18 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fs, ...)
{
	int		len;
	t_data	data;

	data.fs = fs;
	va_start(data.ap, fs);
	len = parse_fs(&data);
	va_end(data.ap);
	return (len);
}

int	print_va(char c, t_data *data)
{
	int		fun_index;
	int		len;
	t_vafun	fun;

	fun_index = ft_instr(FORMAT_STR, c);
	fun = get_fun(fun_index);
	if (fun != NULL)
		len = fun(data);
	else
		len = ft_print_wrongformat(c);
	return (len);
}

t_vafun	get_fun(int fun_index)
{
	t_vafun	funtab[FORMAT_NBR];

	funtab[0] = &ft_print_char;
	funtab[1] = &ft_print_str;
	funtab[2] = &ft_print_point;
	funtab[3] = &ft_print_int;
	funtab[4] = &ft_print_int;
	funtab[5] = &ft_print_uns;
	funtab[6] = &ft_print_lhx;
	funtab[7] = &ft_print_uhx;
	funtab[8] = &ft_print_percent;
	if (fun_index < 0 || fun_index > FORMAT_NBR)
		return (NULL);
	return (funtab[fun_index]);
}
