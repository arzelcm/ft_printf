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

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include "../libft/libft.h"

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
	long		num;
}	t_state;

int		ft_printf(const char *s, ...);

int		is_flag(char c);

void	apply_format(t_state *state);

void	parse_char(t_state *state);

void	parse_string(t_state *state);

void	print_padding(t_state *state, int len);

void	print_complex_padding_left(t_state *state);

void	print_padding_right(t_state *state, int len);

int		is_hex_spec(char c);

int		is_number_spec(char c);

void	parse_percent(t_state *state);

void	parse_pointer(t_state *state);

void	parse_number(t_state *state);

void	parse_hexadecimal(t_state *state);

void	print_precision(t_state *state, int len);

int		count_digits(long nbr);

int		count_hex_digits(unsigned int nbr);

#endif