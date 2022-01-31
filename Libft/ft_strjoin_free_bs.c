/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:44:04 by abrun             #+#    #+#             */
/*   Updated: 2021/10/28 17:51:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_bs(char *s1, const char *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*strjoin;
	size_t			strjoin_len;
	unsigned int	counter;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin_len = s1_len + s2_len + 2;
	strjoin = malloc(sizeof(char) * strjoin_len);
	if (!strjoin)
		return (NULL);
	counter = -1;
	while (++counter < s1_len)
		strjoin[counter] = s1[counter];
	free(s1);
	while (counter - s1_len < s2_len)
	{
		strjoin[counter] = s2[counter - s1_len];
		counter++;
	}
	strjoin[counter++] = '\n';
	strjoin[counter] = 0;
	return (strjoin);
}
