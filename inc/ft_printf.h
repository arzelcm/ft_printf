/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:40:17 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/12 17:11:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *s, ...);

typedef struct s_state
{
	va_list		arg_lst;
	const char	*s;
	int			count;
}	t_state;

void	parse_string(t_state *state);

void	parse_char(t_state *state);

void	parse_pointer(t_state *state);

void	parse_number(t_state *state);

void	parse_hexadecimal(t_state *state);

#endif