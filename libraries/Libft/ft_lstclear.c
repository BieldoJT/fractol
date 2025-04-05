/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:04:46 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:04:46 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_i;
	t_list	*next;

	if (!*lst)
		return ;
	ptr_i = *lst;
	while (ptr_i)
	{
		next = ptr_i->next;
		(*del)(ptr_i->content);
		free(ptr_i);
		ptr_i = next;
	}
	*lst = NULL;
}
