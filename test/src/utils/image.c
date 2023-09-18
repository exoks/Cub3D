/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:59:33 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/18 15:27:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "image.h"

//====< create_image >==========================================================
t_image	*create_image(void *mlx_ptr, int hight, int width)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(mlx_ptr, hight, width);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_len, &image->endian);
	return (image);
}

//====< image_put_pixel >=======================================================
void	mlx_image_put_pixel(t_image *image, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *) image->addr + (x * image->bpp / 8) + (y * image->line_len);
	*pixel = color; 
}

//====< clear_image >===========================================================
void	clear_image(t_image *image)
{
	int	i;

	i = 0;
	while (++i < image->hight * image->width)
		*((int *) image->addr + i) = 0;
}
