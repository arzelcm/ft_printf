/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_handle_helper_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:29:43 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/16 02:01:54 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_pointer(t_state *state)
{
	unsigned long long	ptr_val;
	char				buff[sizeof(void *) * 2];
	int					i;
	int					len;

	ptr_val = (unsigned long long) va_arg(state->arg_lst, void *);
	i = 0;
	while (ptr_val > 0)
	{
		buff[i++] = "0123456789abcdef"[ptr_val % 16];
		ptr_val /= 16;
	}
	len = i + 2 + (i == 0);
	if (!state->justify_left)
        print_padding(state, len);
	ft_putstr("0x", &state->count);
	if (i == 0 && state->count != -1)
		ft_putstr("0", &state->count);
	while (i && state->count > -1)
		ft_putchar(&buff[--i], &state->count);
	if (state->justify_left)
        print_padding(state, len);
}

static int	count_num_digits(long nbr)
{
	int		i;
	long	num;

	num = (long) nbr;
	if (nbr == 0)
		return (1);
	i = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	handle_number(t_state *state)
{
	if (*state->s == 'i' || *state->s == 'd')
		state->num = (long) va_arg(state->arg_lst, int);
	else if (*state->s == 'u')
		state->num = (long) va_arg(state->arg_lst, unsigned int);
	else
		return ;
	// TODO: Delete precision init
	state->precision_len = 0;
	state->buffer_len = count_num_digits((long) state->num);
	print_padding_left(state);
	if (!(state->num == 0 && state->precision == 0) && state->count > -1)
		ft_putnbr(state->num, &state->count);
	print_padding_right(state);
}

int	get_uint_csize(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
		nbr /= 16 + (0 * i++);
	return (i);
}

static void	print_buffer(t_state *state, char **buffer, int i)
{
	char	*buff;

	buff = *buffer;
	if (i == 0 && state->count != -1 && (state->precision != 0))
		ft_putstr("0", &state->count);
	while (i && state->count > -1)
		ft_putchar(&buff[--i], &state->count);
}

void	handle_hex(t_state *state)
{
	char			*buff;
	int				i;
	unsigned int	nbr;

	// TODO: Refactor this malloc
	nbr = va_arg(state->arg_lst, unsigned int);
	state->num = (long) nbr;
	buff = malloc(sizeof(char) * (get_uint_csize(nbr) + 1));
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
	buff[i] = '\0';
	state->precision_len = 0;
	state->buffer = buff;
	state->buffer_len = ft_strlen(buff);
	if (state->buffer_len == 0)
		state->buffer_len = 1;
	print_padding_left(state);
	print_buffer(state, &buff, i);
	print_padding_right(state);
	free(buff);
}
