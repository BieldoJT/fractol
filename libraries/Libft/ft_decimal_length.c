/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:03:15 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:03:15 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_decimal_length(long int nbr)
{
	int	length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr /= 10;
		length++;
	}
	return (length);
}
