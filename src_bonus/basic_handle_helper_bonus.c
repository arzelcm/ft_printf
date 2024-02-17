/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_handle_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:29:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/16 00:55:29 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_string(t_state *state)
{
	char	*str;
	int		str_len;
	int		i;

	i = 0;
	str = va_arg(state->arg_lst, char *);
	if (!str)
        str = "(null)";
	str_len = ft_strlen(str);
	if (state->precision > -1 && str_len > state->precision)
		str_len = state->precision;
	if (!state->justify_left)
		print_padding(state, str_len);
	while (*str && state->count > -1
		&& (state->precision == -1 || i < state->precision))
	{
		ft_putchar(str, &state->count);
		str++;
		i++;
	}
	if (state->justify_left)
	{
		state->padding_char = ' ';
        print_padding(state, str_len);
	}
}

void	handle_char(t_state *state)
{
	char	c;

	c = va_arg(state->arg_lst, int);
	if (!state->justify_left)
        print_padding(state, 1);
	if (state->count != -1)
		ft_putchar(&c, &state->count);
	if (state->justify_left)
	{
		state->padding_char = ' ';
        print_padding(state, 1);
	}
}

void	handle_percent(t_state *state)
{
	char	c;

	c = '%';
	if (!state->justify_left)
        print_padding(state, 1);
	if (state->count != -1)
		ft_putchar(&c, &state->count);
	if (state->justify_left)
	{
		state->padding_char = ' ';
        print_padding(state, 1);
	}
}
