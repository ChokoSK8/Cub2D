/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:27:17 by abrun             #+#    #+#             */
/*   Updated: 2021/10/28 17:33:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	check_file(char *av)
{
	int	av_len;
	int	counter;

	av_len = ft_strlen(av);
	if (av_len < 5)
		return (0);
	counter = 0;
	while (counter++ < av_len - 4)
		av++;
	if (ft_strncmp(av, ".cub", 4))
		return (0);
	return (1);
}
