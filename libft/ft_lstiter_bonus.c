/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:22:52 by arcanava          #+#    #+#             */
/*   Updated: 2024/01/20 04:22:53 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	add1(void *num)
{
	if (num)
	{
		int *numa = (int *) num;
		ft_putnbr_fd(*numa, 1);
	}
}

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
    ft_lstiter(lst, &add1);
    //printf("First lst elem->content: %i\n", *((int *) (lst)->content));
}*/
