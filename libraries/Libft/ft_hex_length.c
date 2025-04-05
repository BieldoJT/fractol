/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:03:28 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:03:28 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_length(unsigned long nbr)
{
	int	length;

	length = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		length++;
	}
	return (length);
}
