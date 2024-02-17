/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:26:38 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/16 00:56:59 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "../libft/libft.h"

int		ft_printf(const char *s, ...);

typedef struct s_state
{
	va_list		arg_lst;
	const char	*s;
	int			count;
	int			has_flags;
	int			hex_prefix;
	int			force_sign;
	int			empty_sign;
	int			justify_left;
	char		padding_char;
	int			width;
	int			precision;
	int			precision_len;
	int			buffer_len;
	char		*buffer;
	long		num;
}	t_state;

void	handle_string(t_state *state);

void	handle_percent(t_state *state);

void	handle_char(t_state *state);

void	handle_pointer(t_state *state);

void	handle_number(t_state *state);

void	handle_hex(t_state *state);

void	print_padding(t_state *state, int len);

void    print_precision(t_state *state, int len);

void	print_padding_left(t_state *state);

void	print_padding_right(t_state *state);