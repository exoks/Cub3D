/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:29:03 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/18 15:30:37 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <mlx.h>
# include <stdio.h>
# include "window.h"

void	draw_grid(t_window *window, int step, int w);
int		draw_ray(t_window *window, int *check_point, int x0, int y0);
int		*get_next_check_point(int *check_point, int step, float slop);

int	main(void)
{
	t_window	window;
	int			*check_point;

	check_point = (int [4]) {0, 0};
	create_window(&window);
	
	draw_grid(&window, 20, 400);
	draw_ray(&window, check_point, 10, 10);

	mlx_loop(window.mlx_ptr);
	return (0);
}

int	draw_ray(t_window *window, int *check_point, int x0, int y0)
{
	int	i;

	i = x0;
	while (++i < 400)
	{
		if (i == check_point[0] && 0.5 * i == check_point[1])
		{
			get_next_check_point(check_point, 20, 0.5);
			printf("P(%d, %d)\n", check_point[0], check_point[1]);
		}
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, i, (0.5 * i) + y0, (255 << 16));
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

	i = 0;
	while (++i < (w / step))
	{
		j = -1;
		while (++j < w)
		{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, j, i * 20, 255);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, i * 20, j, 255);
		}
	}
}	
