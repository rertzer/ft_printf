/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:15:31 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 09:56:36 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_sign(int nb);
static unsigned int	ft_getlen(unsigned int nb, int sign);
static char			*chop_nbr(char *str, unsigned int nb, int sign, \
		unsigned int len);

char	*ft_itoa(int nb)
{
	unsigned int	bignum;
	unsigned int	len;
	int				sign;
	char			*str;

	sign = get_sign(nb);
	bignum = nb * sign;
	len = ft_getlen(bignum, sign);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (chop_nbr(str, bignum, sign, len));
}

static int	get_sign(int nb)
{
	int sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	return (sign);
}

static unsigned int	ft_getlen(unsigned int nb, int sign)
{
	unsigned int	len;

	len = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		++len;
	}
	if (sign < 0)
		++len;
	return (len);
}

static char	*chop_nbr(char *str, unsigned int nb, int sign, unsigned int len)
{
	while (nb / 10)
	{
		--len;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	--len;
	str[len] = (nb % 10) + '0';
	if (sign < 0)
	{
		--len;
		str[len] = '-';
	}
	return (str);
}
