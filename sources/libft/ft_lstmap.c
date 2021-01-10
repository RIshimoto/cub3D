/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 02:35:25 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/14 20:01:32 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nmap;
	t_list	*nlst;

	if (!lst || !f)
		return (0);
	nmap = NULL;
	while (lst)
	{
		if (!(nlst = ft_lstnew(f(lst->content))))
			ft_lstclear(&nmap, del);
		ft_lstadd_back(&nmap, nlst);
		lst = lst->next;
	}
	return (nmap);
}
