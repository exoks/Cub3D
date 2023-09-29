/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:47:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/27 11:12:10 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "window.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

void	render_screen(t_window *window)
{
	int	rays[400];
	int	y;
	int	p_wall;

	int	i = -1;
	while (++i < 400)
			rays[i] = 400 - i;
	window->screen = create_image(window->mlx_ptr, 400, 400);
	i = -1;
	while (++i < 400)
	{
		// p_wall = | (ray / dir) * sqrt(dir^2 - (fv / 2)^2) |
		p_wall = rays[i] * sqrt((100 * 100) + (30 * 30)) / 100;
		printf("P_WALL| ==> %d\n", p_wall);
		y = (p_wall * (64 / 400 - 1) + 400);
		int	j = 200 - (y / 2);
		while (++j <= (200 + (y / 2)))
			mlx_image_pixel_put(window->screen, i, j, 255 << 16);
	}
}

