/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:59:57 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 11:51:32 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	error_map(char *line, t_param *param, char *tab)
{
	free_tab_checks(param);
	if (tab)
		free(tab);
	if (*line)
		ft_putstr_fd("Error\nUn malloc a echoue\n", 2);
	else
		ft_putstr_fd("Error\nLa map n'est pas le dernier element\n", 2);
	free(line);
	return (0);
}

int	fill_tab_map(char *line, int fd, t_param *param)
{
	int		ret;
	char	*tab;

	tab = NULL;
	ret = 1;
	while (ret > 0)
	{
		tab = ft_strjoin_free_bs(tab, line);
		free(line);
		ret = get_next_line(fd, &line);
		if (!tab || ret == -1 || (ret && !*line))
			return (error_map(line, param, tab));
	}
	free(line);
	tab[ft_strlen(tab) - 1] = 0;
	param->tab = tab;
	return (1);
}

char	**get_map(char *tab, t_param *param)
{
	char	**map;
	int		i;
	int		max_width;

	max_width = get_max_width(tab);
	map = malloc(sizeof(int *) * (get_height(tab) + 1));
	if (!map)
	{
		free_tab_checks(param);
		free(tab);
		ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
		return (0);
	}
	i = loop_get_map(tab, map, max_width, param);
	if (!i)
		return (0);
	map[i] = 0;
	return (map);
}

int	loop_get_map(char *tab, char **map, int max_width, t_param *param)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (tab[c])
	{
		j = 0;
		map[i] = malloc(sizeof(int) * (max_width + 1));
		if (!map[i])
		{
			ft_putstr_fd("Error\nUn malloc a échoué !\n", 2);
			free_in_loop_tab(param, i, map, tab);
			return (0);
		}
		while (tab[c] && tab[c] != '\n')
			map[i][j++] = tab[c++];
		while (j < max_width)
			map[i][j++] = 32;
		map[i++][j] = 0;
		if (tab[c])
			c++;
	}
	return (i);
}
