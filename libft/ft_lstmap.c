/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:12:53 by kkinzers          #+#    #+#             */
/*   Updated: 2018/11/11 17:20:51 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *list;

	if (!lst || !*f)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new = (*f)(lst);
	list = new;
	while (lst->next != NULL)
	{
		new->next = (*f)(lst->next);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (list);
}
