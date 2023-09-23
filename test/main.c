/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:29:03 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/23 14:33:28 by oezzaou          ###   ########.fr       */
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
	player->alpha = 0;
}

int	draw_rays(t_window *window)
{
	t_player	*p;
	float		xr;
	float		yr;
	float		β;
	float		i;

	p = &window->player;
	i = -1;
	while (++i < 45)
	{
		β = ((float) p->alpha - i) * M_PI / 180.0;
		xr = p->xp + (p->dir * cos(β)) - (p->fv / 2 * sin(β));
		yr = p->yp + (p->dir * sin(β)) + (p->fv  / 2 * cos(β));
		draw_ray(window, xr, yr);
	}
	return (0);
}

int	draw_ray(t_window *window, float xr, float yr)
{
	float	slop;
	float	m;
	float	i;

	slop = (yr - window->player.yp) / (xr - window->player.xp);
	m = -xr * slop + yr;
	i = window->player.xp;
	while (i >= 0 && i < 400)
	{
		mlx_image_pixel_put(window->minimap, i, i * slop + m, (255 << 8));
		i += ((xr > window->player.xp) - (xr < window->player.xp));
	}
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
