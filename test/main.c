/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:29:03 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/29 18:21:51 by oezzaou          ###   ########.fr       */
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
//	render_screen(&window);
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
	player->fv = 0;
	player->xp = 200;
	player->yp = 200;
	player->dir = 100;
	player->alpha = 0;
}

int	draw_rays(t_window *window)
{
	t_player	*p;
	float		xr;
	float		yr;
	float		β;
	float		tx, ty;
	float		dx, dy;

	p = &window->player;
	β = (p->alpha) * M_PI / 180.0;
	xr = p->xp + (p->dir * cos(β)) - sin(β);
	yr = p->yp + (p->dir * sin(β)) + cos(β);
	draw_ray(window, xr, yr);
//=======================================================
	tx = p->xp + (p->dir * cos(β + (M_PI / 2))) - sin(β);
	ty = p->yp + (p->dir * sin(β + (M_PI / 2))) + cos(β);
	float step = fabs(ty - yr);
	if (fabs(tx - xr) > fabs(ty - yr))
		step = fabs(tx - xr);
	dx = (tx - xr) / step;
	dy = (ty - yr) / step;
	draw_ray(window, tx, ty);
//=======================================================
	int i = -1;
	while (++i < 100)
	{
		mlx_image_pixel_put(window->minimap, tx, ty, (255 << 8));
		tx -= dx;
		ty -= dy;
	}
	return (0);
}

int	draw_ray(t_window *window, float xr, float yr)
{
//	float	slop;
	float	x, y;
	float	step;
	float	xi, yi;

	x = window->player.xp;
	y = window->player.yp;
	step = fabs(yr - y);
	if (fabs(xr - x) > fabs(yr - y))
		step = fabs(xr - x);
	xi = (xr - x) / step;
	yi = (yr - y) / step;
	while ((x >= 0 && x < 400) && (y >= 0 && y < 400))
	{
		mlx_image_pixel_put(window->minimap, roundf(x), roundf(y), (255 << 8));
		x += xi;
		y += yi;
	}
/*	if (xr > x)
		slop = (yr - window->player.yp) / (xr - window->player.xp);
	else
		slop = (window->player.yp - yr) / (window->player.xp - xr);
	xi = (slop > 1.0f) / slop + (slop <= 1.0f);
	yi = (slop < 1.0f) * slop + (slop >= 1.0f);
	while ((x >= 0 && x < 400) && (y >= 0 && y < 400))
	{
		mlx_image_pixel_put(window->minimap, roundf(x), roundf(y), (255 << 8));
		x += xi;
		y += yi;
	}*/
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
