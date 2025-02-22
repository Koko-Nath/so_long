/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:29:17 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/29 11:12:43 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*link;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = f(lst->content);
		link = ft_lstnew(temp);
		if (!link)
		{
			del(temp);
			free (temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, link);
		lst = lst->next;
	}
	return (new);
}
