/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:57:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/01/08 13:59:48 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new;
	t_list *head_to_new;

	head = NULL;
	if (lst && f)
	{
		if (!(head = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		head = (*f)(head);
		head_to_new = head;
		lst = lst->next;
		while (lst)
		{
			if (!(new = ft_lstnew(lst->content, lst->content_size)))
				return (NULL);
			new = (*f)(new);
			head_to_new->next = new;
			head_to_new = new;
			lst = lst->next;
		}
		head_to_new->next = NULL;
	}
	return (head);
}
