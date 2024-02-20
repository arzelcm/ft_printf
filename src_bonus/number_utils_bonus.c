/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utills_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:53:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/02/19 19:53:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_digits(long nbr)
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

int	count_hex_digits(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
		nbr /= 16 + (0 * i++);
	return (i);
}
