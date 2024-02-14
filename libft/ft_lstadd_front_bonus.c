/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:22:16 by arcanava          #+#    #+#             */
/*   Updated: 2024/01/20 04:22:20 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*new_lst;
	t_list	*old_lst;
	t_list	**lst;

	lst = malloc(sizeof(t_list *));
	new_lst = ft_lstnew("New");
	old_lst = ft_lstnew("Old");
	*lst = old_lst;
	printf("First lst elem->content: %s\n", (char *) (*lst)->content);
	ft_lstadd_front(lst, new_lst);
	printf("First lst elem->content: %s\n", (char *) (*lst)->content);
}*/
