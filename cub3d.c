/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:24 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/13 15:05:26 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdlib.h>
# include <stdio.h>
# include "window.h"
# include "image.h"
# include "math.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		events(int keycode, t_image *image);

double	angle = 0.78;

int	main(void)
{
	t_window	window;
	t_image		image;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 400, 400, "        ");

	image.window = &window;
	image.img = mlx_new_image(window.mlx_ptr, 400, 400);
	image.addr = mlx_get_data_addr(image.img, &image.pixel_bits, &image.line_bytes, &image.endian_mode);
	int	j = -1;
	while (++j < 20)
	{
		double	i = -1;
		while (++i < 400)
		{
			if ((tan(angle) * i) + 200 < 400)
				my_mlx_pixel_put(&image, i, (tan(angle) * i ) + 200, 255);
		}
		angle -= 0.05;
	}
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_key_hook(window.win_ptr, events, &image);
	mlx_loop(window.mlx_ptr);	
	return (EXIT_SUCCESS);
}

double	i = -1;

int	events(int keycode, t_image *image)
{
	if (keycode == 38)
	{
		printf("hook ...\n");
		i++;
//		angle -= 0.05;
		int	j = -1;
		while (++j < 20)
		{
			int k = i;
			while (++i < 400)
				if ((tan(angle) * i) + 200 < 400)
					my_mlx_pixel_put(image, i, (tan(angle) * i) + 200 + i, 255);
			angle -= 0.05;
		}
	}
	if (keycode == 3)
		printf("");
	mlx_put_image_to_window(image->window->mlx_ptr, image->window->win_ptr, image->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_bytes + x * (image->pixel_bits / 8));
	*(unsigned int*) dst = color;
}
