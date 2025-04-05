/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:02:06 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:02:06 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arguments_x(unsigned int nbr, char type)
{
	char	*num;
	int		bytes;
	int		i;

	i = 0;
	if (!nbr)
		return (write(1, "0", sizeof(char) * 1));
	num = (char *)malloc((ft_hex_length(nbr) + 1) * sizeof(char));
	while (nbr)
	{
		num[i] = ft_decimal_converter_to_hex(nbr % 16, type);
		nbr /= 16;
		i++;
	}
	num[i] = '\0';
	bytes = ft_print_reversed_str(num);
	ft_free_ptr(&num);
	return (bytes);
}
