/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_handle_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:00:43 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/12 18:42:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_pointer(t_state *state)
{
	unsigned long long	ptr_val;
	char				buff[sizeof(void *) * 2];
	int					i;

	ptr_val = (unsigned long long) va_arg(state->arg_lst, void *);
	i = 0;
	while (ptr_val > 0)
	{
		buff[i++] = "0123456789abcdef"[ptr_val % 16];
		ptr_val /= 16;
	}
	ft_putstr("0x", &state->count);
	if (i == 0 && state->count != -1)
		ft_putstr("0", &state->count);
	while (i && state->count > -1)
		ft_putchar(&buff[--i], &state->count);
}

void	handle_number(t_state *state)
{
	long	num;

	if (*state->s == 'i' || *state->s == 'd')
		num = (long) va_arg(state->arg_lst, int);
	else if (*state->s == 'u')
		num = (long) va_arg(state->arg_lst, unsigned int);
	else
		return ;
	ft_putnbr(num, &state->count);
}

int	get_uint_csize(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
		nbr /= 16 + (0 * i++);
	return (i);
}

void	handle_hex(t_state *state)
{
	char			*buff;
	int				i;
	unsigned int	nbr;

	nbr = va_arg(state->arg_lst, unsigned int);
	buff = malloc(sizeof(char) * get_uint_csize(nbr));
	if (!buff)
	{
		state->count = -1;
		return ;
	}
	i = 0;
	while (nbr > 0)
	{
		if (*state->s == 'X')
			buff[i++] = "0123456789ABCDEF"[nbr % 16];
		else
			buff[i++] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	if (i == 0 && state->count != -1)
		ft_putstr("0", &state->count);
	while (i && state->count > -1)
		ft_putchar(&buff[--i], &state->count);
	free(buff);
}
