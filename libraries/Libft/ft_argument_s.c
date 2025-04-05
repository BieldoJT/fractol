/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-conc <gda-conc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:01:41 by gda-conc          #+#    #+#             */
/*   Updated: 2024/11/18 22:01:41 by gda-conc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_argument_s(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", sizeof(char) * 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
