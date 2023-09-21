/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:29:03 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/20 19:59:07 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <mlx.h>
# include <stdio.h>
# include "window.h"
# include "minimap.h"
# include "events.h"
# include "math.h"

int		*get_next_check_point(int *check_point, int step, float slop);

int	main(void)
{
	t_window	window;
	int			*check_point;

	check_point = (int [4]) {0, 0};
	create_window(&window);

	create_minimap(&window);
	player_init(&window.player);
	draw_grid(&window, 20, 400);
	draw_rays(&window);

	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.minimap->img, 0, 0);
	mlx_key_hook(window.win_ptr, events, &window);	
	mlx_loop(window.mlx_ptr);
	return (0);
}

void	player_init(t_player *player)
{
	player->fv = 60;
	player->xp = 200;
	player->yp = 200;
	player->dir = 100;
	player->alpha = 0.0;
}

int	draw_rays(t_window *window)
{
	float	x, y;
	float	xr;
	float	yr;
	float	slop;
	int		i;
	float		b;

	b = ((float) window->player.alpha) * M_PI / 180.0;
	x = window->player.xp + window->player.dir;
	y = window->player.yp + (window->player.fv / 2);
	xr = x * cos(b) - (y * sin(b));
	yr = x * sin(b) + (y * cos(b));
	printf("(xr, yr) : (%f, %f)\n", xr, yr);
	i = window->player.fv;
	while (--i > 0)
	{
		slop = (yr - i - window->player.yp) / (xr - window->player.xp);
		draw_ray(window, slop);	
	}
	return (0);
}

int	draw_ray(t_window *window, float slop)
{
	float	i;

	i = -1;
	while (++i < 400)
	{
		/*if (i == check_point[0] && 0.5 * i == check_point[1])
		{
			get_next_check_point(check_point, 20, 0.5);
			printf("P(%d, %d)\n", check_point[0], check_point[1]);
		}*/
		mlx_image_pixel_put(window->minimap, i + window->player.xp, roundf(slop * i) + window->player.yp, (255 << 16));
	}
	// return the length of the ray
	return (0);
}

int	*get_next_check_point(int *check_point, int step, float slop)
{
	check_point[0] += (step / slop) + step * (slop < 1);
	check_point[1] += step + slop * (slop < 1);
	return (check_point);
}

void	draw_grid(t_window *window, int step, int w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (w / step))
	{
		j = -1;
		while (++j < w)
		{
				mlx_image_pixel_put(window->minimap, j, i * 20, 255);
				mlx_image_pixel_put(window->minimap, i * 20, j, 255);
		}
	}
}	
