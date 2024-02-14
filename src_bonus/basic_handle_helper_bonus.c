/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_handle_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:29:28 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/13 11:29:31 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_string(t_state *state)
{
	char	*str;

	str = va_arg(state->arg_lst, char *);
	if (!str)
		str = "(null)";
	while (*str && state->count > -1)
	{
		ft_putchar(str, &state->count);
		str++;
	}
}

void	handle_char(t_state *state)
{
	char	c;

	c = va_arg(state->arg_lst, int);
	ft_putchar(&c, &state->count);
}
