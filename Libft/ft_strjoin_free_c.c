/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:43:18 by abrun             #+#    #+#             */
/*   Updated: 2021/10/28 17:43:48 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_c(char *s1, char c)
{
	size_t			s1_len;
	char			*strjoin;
	unsigned int	counter;

	s1_len = ft_strlen(s1);
	strjoin = malloc(s1_len + 2);
	if (!strjoin)
	{
		free(s1);
		return (0);
	}
	counter = -1;
	while (++counter < s1_len)
		strjoin[counter] = s1[counter];
	free(s1);
	strjoin[counter++] = c;
	strjoin[counter] = 0;
	return (strjoin);
}
