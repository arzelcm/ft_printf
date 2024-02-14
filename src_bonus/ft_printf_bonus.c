/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:30:09 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/13 23:16:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

// TODO: Define behaviour when params count is bigger than % on the string.

int	handle_specifier(t_state *state)
{
	if (!state->s
		|| !*state->s
		|| (!state->has_flags && !((*state->s) + 2))
		|| (state->has_flags && !((*state->s) + 1)))
		return (0);
	state->s += !state->has_flags;
	if (*state->s == 's')
		handle_string(state);
	else if (*state->s == 'c')
		handle_char(state);
	else if (*state->s == '%')
		ft_putchar("%", &state->count);
	else if (*state->s == 'p')
		handle_pointer(state);
	else if (*state->s == 'd' || *state->s == 'i' || *state->s == 'u')
		handle_number(state);
	else if (*state->s == 'x' || *state->s == 'X')
		handle_hex(state);
	else
		return (0);
	return (1);
}

int		is_flag(char c)
{
	return (c == '#' || c == '+' || c == ' '
		|| c == '-' || c == '.' || ft_isdigit(c));
}

void    init_flags(t_state *state)
{
	state->has_flags = 0;
	state->hex_prefix = 0;
	state->force_sign = 0;
	state->empty_sign = 0;
	/*state->empty_sign = 0;
	*state->empty_sign = 0;*/
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
		state->s++;
	}
	if (!state->has_flags)
		state->s--;
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
		if (*state.s == '%' || state.has_flags)
			handle_specifier(&state);
		else
			ft_putchar(state.s, &state.count);
		if (state.count == -1)
			return (-1);
		state.s++;
	}
	va_end(state.arg_lst);
	return (state.count);
}
