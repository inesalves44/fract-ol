/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:21:35 by idias-al          #+#    #+#             */
/*   Updated: 2022/11/12 20:07:50 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*prev;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}
