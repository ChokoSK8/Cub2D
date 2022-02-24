/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:56:59 by abrun             #+#    #+#             */
/*   Updated: 2022/02/22 14:24:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_so_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("SO", line, param->checks[1]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (error_malloc());
	c = 1;
	counter = 0;
	while (line[++c] && ft_isspace(line[c]))
		;
	c--;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->so = ft_strdup(path);
	if (!param->so)
	{
		free(path);
		return (error_malloc());
	}
	free(path);
	return (2);
}

int	get_ea_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("EA", line, param->checks[2]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (error_malloc());
	c = 1;
	counter = 0;
	while (line[++c] && ft_isspace(line[c]))
		;
	c--;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->ea = ft_strdup(path);
	if (!param->ea)
	{
		free(path);
		return (error_malloc());
	}
	free(path);
	return (3);
}

int	get_we_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("WE", line, param->checks[3]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (error_malloc());
	c = 1;
	counter = 0;
	while (line[++c] && ft_isspace(line[c]))
		;
	c--;
	while (line[c++] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->we = ft_strdup(path);
	if (!param->we)
	{
		free(path);
		return (error_malloc());
	}
	free(path);
	return (4);
}

int	get_no_path(t_param *param, char *line)
{
	char	*path;
	int		counter;
	int		c;

	if (!check_texture("NO", line, param->checks[0]))
		return (0);
	path = malloc(ft_strlen(line));
	if (!path)
		return (error_malloc());
	c = 2;
	counter = 0;
	while (line[++c] && ft_isspace(line[c]))
		;
	c--;
	while (line[++c] && ft_isprint(line[c]) && !ft_isspace(line[c]))
		path[counter++] = line[c];
	path[counter] = 0;
	param->no = ft_strdup(path);
	if (!param->no)
	{
		free(path);
		return (error_malloc());
	}
	free(path);
	return (1);
}
