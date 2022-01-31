/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:21:26 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 12:16:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_next_line(int fd, char **line)
{
	char	buf;
	int		ret;

	if (!checker_and_init(fd, line))
		return (-1);
	ret = read(fd, &buf, 1);
	while (ret && buf != '\n')
	{
		*line = ft_strjoin_free_c(*line, buf);
		if (!*line)
			return (0);
		ret = read(fd, &buf, 1);
	}
	return (ret);
}

int	checker_and_init(int fd, char **line)
{
	if (fd < 0 || !line)
		return (0);
	*line = malloc(1);
	if (!*line)
		return (0);
	line[0][0] = 0;
	return (1);
}

int	ft_isalnum(int c)
{
	if (((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')))
		return (1);
	return (0);
}

char	*error_strjoin(char *s1, char *strjoin)
{
	free(s1);
	free(strjoin);
	return (NULL);
}

char	*ft_strjoin_free(char *s1, char c)
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
	{
		if (ft_isalnum(s1[counter]))
			strjoin[counter] = s1[counter];
		else
			return (error_strjoin(s1, strjoin));
	}
	free(s1);
	strjoin[counter++] = c;
	strjoin[counter] = 0;
	return (strjoin);
}
