/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:03:58 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 12:06:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(int *tab, size_t size)
{
	while (size--)
	{
		ft_putnbr_fd(*tab, 1);
		write(1, "\n", 1);
		tab++;
	}
}