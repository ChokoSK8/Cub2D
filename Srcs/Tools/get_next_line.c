/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:21:26 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 16:24:41 by abrun            ###   ########.fr       */
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
	while (ret && buf != '\n' && ft_isascii(buf))
	{
		*line = ft_strjoin_free_c(*line, buf);
		if (!*line)
			return (-1);
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
