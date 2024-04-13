/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:39:04 by rertzer           #+#    #+#             */
/*   Updated: 2024/04/13 11:56:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define FORMAT_STR	"cspdiuxX%"
# define FORMAT_NBR 9
# define FLAGS_STR "-0.# +"
# define FLAGS_NBR 7
# define BASETEN "0123456789"
# define BASEUHEX "0123456789ABCDEF"
# define BASELHEX "0123456789abcdef"

typedef struct s_data
{
	const char	*fs;
	va_list		ap;
}	t_data;

typedef unsigned int		t_uint;
typedef unsigned long long	t_ull;
typedef int					(*t_vafun)(t_data *data);

/* ft_printf.c functions */
int		ft_printf(const char *fs, ...);
int		print_va(char c, t_data *data);
t_vafun	get_fun(int i);
/* parse_fs functions */
int		parse_fs(t_data *data);
int		set_len(int total_len, int len);
/* ft_print_alpha functions */
int		ft_print_char(t_data *data);
int		ft_print_str(t_data *data);
int		ft_print_percent(t_data *data);
int		ft_print_wrongformat(char c);
/* ft_print_num functions */
int		ft_print_int(t_data *data);
int		ft_print_uns(t_data *data);
int		ft_print_lhx(t_data *data);
int		ft_print_uhx(t_data *data);
int		ft_print_point(t_data *data);
/* ft_printf_utils functions */
int		ft_instr(char *str, char c);
int		print_data(t_data* data, int start, int end);
int		print_str_and_free(char *str);
/* uxitoa.c functions */
char	*ft_uxitoa(unsigned int nb, char *base);
/* pointoa.c functions */
char	*ft_pointoa(t_ull nb);
/* ft_itoa functions */
char	*ft_itoa(int nb);
/* ft_strlen functions */
size_t	ft_strlen(const char *s);
#endif
