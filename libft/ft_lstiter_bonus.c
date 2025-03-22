/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:35:35 by ntordjma          #+#    #+#             */
/*   Updated: 2024/11/29 11:54:55 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	void	*ptr;

	if (!lst || !f)
		return ;
	while (lst)
	{
		ptr = lst->content;
		if (ptr)
			f(ptr);
		lst = lst->next;
	}
}
