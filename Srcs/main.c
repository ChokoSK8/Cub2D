/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:55:20 by abrun             #+#    #+#             */
/*   Updated: 2022/02/24 14:41:45 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int ac, char **av)
{
	t_param		param;

	if (ac != 2 || !check_file(av[1]))
	{
		return (error_arg(ac));
	}
	param.cub = av[1];
	if (!init_param(&param))
		return (1);
	param.img_map.image = mlx_new_image(param.mlx,
			param.map.max_width * param.map.len_pix,
			param.map.height * param.map.len_pix);
	param.img_map.data = mlx_get_data_addr(param.img_map.image,
			&param.img_map.bpp, &param.img_map.size_line,
			&param.img_map.endian);
	display_map(param.map, param);
	display_multi_angle(&param);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_do_key_autorepeatoff(param.mlx);
	mlx_hook(param.win, 2, 1L << 0, keypressed, &param);
	mlx_hook(param.win, 3, 1L << 1, keyreleased, &param);
	mlx_hook(param.win, 33, 1L << 17, destroy_win, &param);
	mlx_loop_hook(param.mlx, display, &param);
	mlx_loop(param.mlx);
	return (0);
}

int	error_arg(int ac)
{
	if (ac == 2)
		ft_putstr_fd("Error\nIl n'y pas de *.cub passé en argument !\n", 2);
	else
		ft_putstr_fd("Error\nIl n'y a pas exactement 2 arguments\n", 2);
	return (1);
}
