/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:05:45 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/16 00:55:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	print_padding(t_state *state, int len)
{
	int	i;

	if (state->width == -1)
		return ;
	i = 0;
	while (i < state->width - len
		&& state->count > -1)
	{
		ft_putchar(&state->padding_char, &state->count);
		i++;
	}
}

void	print_precision(t_state *state, int	len)
{
	int	i;

	if (state->precision == -1)
        return ;
    i = 0;
    while (i < len && state->count > -1)
    {
        ft_putstr("0", &state->count);
        i++;
    }
}

static void	handle_sign_flag_group(t_state *state)
{
	if (state->num >= 0)
	{
		if (state->force_sign)
			ft_putstr("+", &state->count);
		else if (state->empty_sign)
			ft_putstr(" ", &state->count);
	}
	else
	{
		ft_putstr("-", &state->count);
		state->num *= -1;
	}
}

static void	print_hex_prefix(t_state *state)
{
	char	*prefix;
	// TODO: if i < 0 should not do anything
	if (state->num > 0 && state->count != -1 && state->hex_prefix)
	{
		prefix = "0x";
		if (*state->s == 'X')
			prefix = "0X";
		ft_putstr(prefix, &state->count);
	}
}

static int	is_hex_spec(t_state *state)
{
	return (*state->s == 'x' || *state->s == 'X');
}

void	print_value_prefix(t_state *state)
{
	if (*state->s == 'i' || *state->s == 'd')
		handle_sign_flag_group(state);
	else if (is_hex_spec(state))
		print_hex_prefix(state);
}

void	print_padding_left(t_state *state)
{
	if (state->precision > state->buffer_len)
		state->precision_len = state->precision - state->buffer_len;
	if (state->precision == 0 && state->num == 0)
		state->buffer_len = 0;
	if ((state->force_sign || state->empty_sign || state->num < 0)
        && *state->s != 'u' && !is_hex_spec(state))
        state->buffer_len++;
	if (is_hex_spec(state) && state->hex_prefix && state->num > 0)
		state->buffer_len += 2;
	if (state->padding_char == '0' && state->precision > -1)
		state->padding_char = ' ';
	if ((!state->justify_left && state->padding_char == ' ')
		|| (state->padding_char == '0' && state->precision > -1))
        print_padding(state, state->buffer_len + state->precision_len);
	print_value_prefix(state);
	if (!state->justify_left && state->padding_char == '0')
        print_padding(state, state->buffer_len + state->precision_len);
	if (state->precision > -1)
        print_precision(state, state->precision_len);
}

void	print_padding_right(t_state *state)
{
	if (state->justify_left)
	{
		state->padding_char = ' ';
        print_padding(state, state->buffer_len + state->precision_len);
	}
}