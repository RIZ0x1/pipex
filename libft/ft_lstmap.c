/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 07:32:36 by jcarlena          #+#    #+#             */
/*   Updated: 2020/11/12 07:33:48 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	if (!lst)
		return (NULL);
	if ((new = ft_lstnew(f(lst->content))) == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	p = new;
	lst = lst->next;
	while (lst)
	{
		if ((p->next = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&new, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		lst = lst->next;
		p = p->next;
	}
	p->next = NULL;
	return (new);
}
