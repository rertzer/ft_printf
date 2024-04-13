/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:31:29 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 12:01:49 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_instr(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	print_data(t_data *data, int start, int end)
{
	int	len;

	len = end - start + 1;
	write(1, &data->fs[start], len);
	return (len);
}

int	print_str_and_free(char *str)
{
	int		len;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	write (1, str, len);
	free(str);
	return (len);
}
