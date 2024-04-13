/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:09:04 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 12:01:44 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_fs(t_data *data)
{
	int		current;
	int		start;
	int		len;
	int		total_len;

	start = 0;
	current = 0;
	total_len = 0;
	while (data->fs[current])
	{
		if (data->fs[current] == '%')
		{
			total_len += print_data(data, start, current - 1);
			len = print_va(data->fs[current + 1], data);
			if (len < 0)
				return (len);
			total_len += len;
			++current;
			start = current + 1;
		}
	++current;
	}
	total_len += print_data(data, start, current - 1);
	return (total_len);
}

int	set_len(int total_len, int len)
{
	if (len < 0)
		total_len = len;
	else
		total_len += len;
	return (total_len);
}
