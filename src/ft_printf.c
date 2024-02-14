/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:16:10 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/13 16:01:27 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO: Define behaviour when params count is bigger than % on the string.

int	handle_specifier(t_state *state, int has_percent)
{
	if (!state->s
		|| !*state->s
		|| (has_percent && !((*state->s) + 2))
		|| (!has_percent && !((*state->s) + 1)))
		return (0);
	state->s += has_percent;
	if (*state->s == 's')
		handle_string(state);
	else if (*state->s == 'c')
		handle_char(state);
	else if (*state->s == '%')
		ft_putchar("%", &state->count);
	else if (*state->s == 'p')
		handle_pointer(state);
	else if (*state->s == 'd' || *state->s == 'i' || *state-> s == 'u')
		handle_number(state);
	else if (*state->s == 'x' || *state->s == 'X')
		handle_hex(state);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	t_state	state;

	va_start(state.arg_lst, s);
	state.count = 0;
	state.s = s;
	while (*state.s)
	{
		if (*state.s != '%' || !handle_specifier(&state, 1))
			ft_putchar(state.s, &state.count);
		if (state.count == -1)
			return (-1);
		state.s++;
	}
	va_end(state.arg_lst);
	return (state.count);
}
