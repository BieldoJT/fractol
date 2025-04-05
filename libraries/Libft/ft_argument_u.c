/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:01:49 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:01:49 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned_nbr(unsigned int nbr)
{
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	else
	{
		ft_put_unsigned_nbr(nbr / 10);
		ft_put_unsigned_nbr(nbr % 10);
	}
}

int	ft_argument_u(unsigned int nbr)
{
	ft_put_unsigned_nbr(nbr);
	return (ft_decimal_length(nbr));
}
