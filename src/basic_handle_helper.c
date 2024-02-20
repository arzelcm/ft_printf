/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_handles_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:02:33 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/12 17:07:42 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_string(t_state *state)
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

void	parse_char(t_state *state)
{
	char	c;

	c = va_arg(state->arg_lst, int);
	ft_putchar(&c, &state->count);
}
