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

void	parse_specifier(t_state *state)
{
	state->s++;
	if (*state->s == 's')
		parse_string(state);
	else if (*state->s == 'c')
		parse_char(state);
	else if (*state->s == '%')
		ft_putchar("%", &state->count);
	else if (*state->s == 'p')
		parse_pointer(state);
	else if (*state->s == 'd' || *state->s == 'i' || *state-> s == 'u')
		parse_number(state);
	else if (*state->s == 'x' || *state->s == 'X')
		parse_hexadecimal(state);
	else
		state->s--;
}

int	ft_printf(const char *s, ...)
{
	t_state	state;

	va_start(state.arg_lst, s);
	state.count = 0;
	state.s = s;
	while (*state.s)
	{
		if (*state.s == '%')
			parse_specifier(&state);
		else
			ft_putchar(state.s, &state.count);
		if (state.count == -1)
			return (-1);
		state.s++;
	}
	va_end(state.arg_lst);
	return (state.count);
}
