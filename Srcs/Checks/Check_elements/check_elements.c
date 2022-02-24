/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:13:27 by abrun             #+#    #+#             */
/*   Updated: 2022/02/22 15:46:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	check_color(int id, char *line)
{
	if (!ft_strnchr(line, id, 1))
	{
		ft_putstr_char("Error\nErreur de syntaxe pour l'élément : ", id, 2);
		return (0);
	}
	line++;
	while (ft_isspace(*line))
		line++;
	if (!check_rgb(line))
	{
		ft_putstr_char("Error\nErreur de syntaxe pour l'élément : ", id, 2);
		return (0);
	}
	return (1);
}

int	check_texture(char *id, char *line, int ret)
{
	int		fd;
	size_t	id_len;

	id_len = ft_strlen(id);
	while (ft_isspace(*line))
		line++;
	if (!check_syntaxe(id, id_len, line, id))
		return (0);
	line += id_len;
	while (ft_isspace(*line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd < 2 || ret)
	{
		ft_putstr_str("Error\nIl y a un probleme avec la texture : ", id, 2);
		if (ret && fd > 0)
			close(fd);
		return (0);
	}
	return (1);
}

int	check_syntaxe(char *s, size_t len, char *line, char *id)
{
	if (!ft_strnstr(line, s, len))
	{
		ft_putstr_str("Error\nErreur de syntaxe pour l'élément : ", id, 2);
		return (0);
	}
	return (1);
}

int	is_rgb(char *line)
{
	char	rgb[3];
	int		n;
	int		a;

	n = 0;
	while (*line && ft_isdigit(*line))
	{
		rgb[n] = *line;
		line++;
		n++;
	}
	rgb[n] = 0;
	a = ft_atoi(rgb);
	if (a >= 0 && a <= 255 && n)
		return (n);
	return (0);
}

int	check_rgb(char *line)
{
	int	n;
	int	loop;

	loop = 3;
	while (loop--)
	{
		while (*line && ft_isspace(*line))
			line++;
		n = is_rgb(line);
		if (!n)
			return (0);
		line += n;
		while (loop && *line && ft_isspace(*line))
			line++;
		if (*line && *line == ',')
			line++;
		else if (loop)
			return (0);
	}
	if (*line)
		return (0);
	return (1);
}
