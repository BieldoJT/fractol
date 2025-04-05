/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:08:10 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:08:10 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	find_size;

	i = 0;
	find_size = ft_strlen(to_find);
	if (!find_size)
		return ((char *) str);
	if (!size)
		return (0);
	while (str[i] && i + find_size <= size)
	{
		if (!ft_strncmp(&str[i], to_find, find_size))
			return ((char *) &str[i]);
		i++;
	}
	return (0);
}
