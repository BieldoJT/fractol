/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:02:54 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:02:54 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr_elements, size_t element_size)
{
	void	*ptr;

	ptr = malloc(nbr_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nbr_elements * element_size);
	return (ptr);
}
