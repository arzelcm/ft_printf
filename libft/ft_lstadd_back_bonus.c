/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:21:53 by arcanava          #+#    #+#             */
/*   Updated: 2024/01/20 04:22:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
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

	int num = -42;
	t_list *back = ft_lstnew((void *) &num);
	t_list **new_lst = malloc(sizeof(t_list *));
	*new_lst = lst;
	ft_lstadd_back(new_lst, back);

	ft_putnbr_fd(*((int *) ft_lstlast(lst)->content), 1);
}*/
