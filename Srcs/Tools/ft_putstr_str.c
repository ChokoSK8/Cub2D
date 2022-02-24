/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:04:05 by abrun             #+#    #+#             */
/*   Updated: 2021/10/29 16:30:33 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ft_putstr_str(char *s, char *id, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putstr_fd(id, fd);
	ft_putstr_fd(" !\n", fd);
}

void	ft_putstr_char(char *s, char id, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd(id, fd);
	ft_putstr_fd(" !\n", fd);
}
