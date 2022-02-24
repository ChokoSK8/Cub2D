/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:55:36 by abrun             #+#    #+#             */
/*   Updated: 2022/02/22 14:55:18 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_color(char *line, t_param *param, int d)
{
	int		*tab;
	int		ret;

	if (!check_color(d, line))
		return (0);
	tab = get_color_fill_tab(line);
	if (!tab)
		return (error_malloc());
	if (d == 'F')
	{
		if (!(fill_floor(param, tab)))
			ret = 0;
		else
			ret = 5;
	}
	else
	{
		if (!(fill_roof(param, tab)))
			ret = 0;
		else
			ret = 6;
	}
	free(tab);
	return (ret);
}

int	*get_color_fill_tab(char *line)
{
	int		*tab;

	tab = malloc(sizeof(int) * 3);
	if (!tab)
		return (0);
	while (*line && !ft_isdigit(*line))
		line++;
	tab[0] = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line && *line != ',')
		line++;
	tab[2] = ft_atoi(++line);
	return (tab);
}

int	fill_floor(t_param *param, int *tab)
{
	int		counter;

	if (param->checks[4])
	{
		ft_putstr_fd("Error\nIl y a 2 fois la couleur du sol !\n", 2);
		return (0);
	}
	counter = 0;
	param->floor = malloc(sizeof(int) * 3);
	if (!param->floor)
		return (error_malloc());
	while (counter < 3)
	{
		param->floor[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int	fill_roof(t_param *param, int *tab)
{
	int		counter;

	if (param->checks[5])
	{
		ft_putstr_fd("Error\nIl y a 2 fois la couleur du toit !\n", 2);
		return (0);
	}
	counter = 0;
	param->roof = malloc(sizeof(int) * 3);
	if (!param->roof)
		return (error_malloc());
	while (counter < 3)
	{
		param->roof[counter] = tab[counter];
		counter++;
	}
	return (1);
}
