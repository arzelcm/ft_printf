/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:09 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/15 23:27:56 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

// TODO: Define behaviour when params count is bigger than % on the string.

/*static void	fill_left_padding(t_state *state)
{
	if (!state->justify_left)
	{
		return ;
	}
	// TODO: Precision if u, i, d
	// TODO: If no precision, width
}*/

static void resolve_flags_conflicts(t_state *state)
{
	// TODO: Check max width and precision values
	// TODO: 
	// fill_left_padding(state);
	if (!state->has_flags)
		return ;
}

int	handle_specifier(t_state *state)
{
	if (*state->s == 's')
		handle_string(state);
	else if (*state->s == 'c')
		handle_char(state);
	else if (*state->s == '%')
		handle_percent(state);
	else if (*state->s == 'p')
		handle_pointer(state);
	else if (*state->s == 'd' || *state->s == 'i' || *state->s == 'u')
		handle_number(state);
	else if (*state->s == 'x' || *state->s == 'X')
		handle_hex(state);
	else
	{
		state->s--;
		return (0);
	}
	return (1);
}

int		is_flag(char c)
{
	return (c == '#' || c == '+' || c == ' '
		|| c == '-' || c == '0');
}

void    init_flags(t_state *state)
{
	state->has_flags = 0;
	state->hex_prefix = 0;
	state->force_sign = 0;
	state->empty_sign = 0;
	state->justify_left = 0;
	state->padding_char = ' ';
	state->width = 0;
	state->precision = -1;
	state->precision_len = 0;
	state->buffer_len = 0;
	state->num = 0;
}

void	set_width(t_state *state)
{
	while (ft_isdigit(*state->s))
	{
		state->width *= 10;
		state->width += *state->s - '0';
		state->s++;
	}
	if (state->width > -1)
		state->has_flags = 1;
}

void	set_precision(t_state *state)
{
	if (*state->s != '.')
		return ;
	state->has_flags = 1;
	state->precision = 0;
	state->s++;
	while (ft_isdigit(*state->s))
	{
		state->precision *= 10;
		state->precision += *state->s - '0';
		state->s++;
	}
}

void	handle_flags(t_state *state)
{
	state->s++;
	while (is_flag(*state->s))
	{
		state->has_flags = 1;
		if (*state->s == '#')
			state->hex_prefix = 1;
		else if (*state->s == '+')
			state->force_sign = 1;
		else if (*state->s == ' ')
			state->empty_sign = 1;
		else if (*state->s == '-')
			state->justify_left = 1;
		else if (*state->s == '0')
			state->padding_char = '0';
		state->s++;
	}
	set_width(state);
	set_precision(state);
	resolve_flags_conflicts(state);
	handle_specifier(state);
}

int	ft_printf(const char *s, ...)
{
	t_state	state;

	va_start(state.arg_lst, s);
	state.s = s;
	state.count = 0;
	while (*state.s)
	{
		init_flags(&state);
		if (*state.s == '%')
			handle_flags(&state);
		else
			ft_putchar(state.s, &state.count);
		if (state.count == -1)
			return (-1);
		state.s++;
	}
	va_end(state.arg_lst);
	return (state.count);
}
