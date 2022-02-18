/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:13:27 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 11:36:22 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	check_color(int id, char *line)
{
	while (ft_isspace(*line))
		line++;
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
	if (!check_syntaxe("./", 2, line, id))
		return (0);
	line += 2;
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

int	check_rgb(char *line)
{
	int	counter;
	int	loop;
	int	color;

	loop = 3;
	while (loop--)
	{
		counter = 3;
		color = ft_atoi(line);
		if (color > 255)
			return (0);
		while (*line && *line != ',' && ft_isdigit(*line))
		{
			line++;
			counter--;
		}
		if (counter < 0 || counter == 3)
			return (0);
		if (*line && loop)
			line++;
	}
	if (*line)
		return (0);
	return (1);
}
