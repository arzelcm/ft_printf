/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:23:04 by arcanava          #+#    #+#             */
/*   Updated: 2024/01/20 04:23:07 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr_node;

	curr_node = lst;
	while (curr_node && curr_node->next)
		curr_node = curr_node->next;
	return (curr_node);
}
/*
int main(void)
{
    size_t  i = 0;
    t_list  *lst = ft_lstnew(0);
    t_list  *prev_list = lst;
    while (i < 43)
    {
        prev_list->next = ft_lstnew((void *) &i);
        prev_list = prev_list->next;
        i++;
    }

    ft_putnbr_fd(*((int *) ft_lstlast(lst)->content), 1);
}*/
