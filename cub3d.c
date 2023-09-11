/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:24 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/11 15:14:54 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "window.h"
# include "image.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_bytes + x * (image->pixel_bits / 8));
	*(unsigned int*) dst = color;
}

int	main(void)
{
	t_window	window;
	t_image		image;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 400, 400, "        ");

	image.img = mlx_new_image(window.mlx_ptr, 400, 400);
	image.addr = mlx_get_data_addr(image.img, &image.pixel_bits, &image.line_bytes, &image.endian_mode);
	int	i = -1;
	while (++i < 400)
		my_mlx_pixel_put(&image, i, i, 255);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img, 0, 0);
	mlx_loop(window.mlx_ptr);	
	return (0);
}
