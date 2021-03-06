/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:58:31 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 11:58:37 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_param_cub(t_param *param)
{
	char	*line;
	int		fd;

	fd = open(param->cub, O_DIRECTORY);
	if (fd != -1)
		return (exit_get_param(param, fd));
	fd = open(param->cub, O_RDONLY);
	if (fd < 2)
		return (exit_get_param(param, fd));
	line = NULL;
	line = fill_elements(param, fd, line);
	if (!line)
		return (0);
	if (!check_all(param->checks, param))
	{
		free(line);
		return (0);
	}
	if (!fill_tab_map(line, fd, param))
		return (0);
	return (1);
}

char	*fill_elements(t_param *param, int fd, char *line)
{
	int	ret;

	ret = 1;
	while (ret != 9 && ret)
	{
		line = get_element(fd, param);
		if (!line)
			return (0);
		ret = fill_param(param, line);
		if (!ret)
		{
			free_tab_checks(param);
			free(line);
			return (0);
		}
		if (ret != 9)
		{
			param->checks[ret - 1] = 1;
			free(line);
		}
	}
	return (line);
}

char	*get_element(int fd, t_param *param)
{
	int		find;
	char	*line;

	find = 0;
	line = NULL;
	while (!find)
	{
		if (get_next_line(fd, &line) < 1)
		{
			free_tab_checks(param);
			ft_putstr_fd("Error\nProbleme lecture ou pas de map!\n", 2);
			if (line)
				free(line);
			return (NULL);
		}
		if (*line)
			find = 1;
		else
			free(line);
	}
	return (line);
}

int	fill_param(t_param *param, char *line)
{
	if (ft_strnstr(line, "NO", 2))
		return (get_no_path(param, line));
	else if (ft_strnstr(line, "SO", 2))
		return (get_so_path(param, line));
	else if (ft_strnstr(line, "EA", 2))
		return (get_ea_path(param, line));
	else if (ft_strnstr(line, "WE", 2))
		return (get_we_path(param, line));
	else if (ft_strnchr(line, 'C', 1))
		return (get_color(line, param, 'C'));
	else if (ft_strnchr(line, 'F', 1))
		return (get_color(line, param, 'F'));
	else if (is_map(line))
		return (9);
	printf("Error\nLa ligne \"%s\" est invalide\n", line);
	return (0);
}

int	is_map(char *line)
{
	while (*line)
	{
		if (ft_isalpha(*line))
			return (0);
		line++;
	}
	return (1);
}
