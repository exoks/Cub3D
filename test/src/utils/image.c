/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:59:33 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/24 13:56:47 by oezzaou          ###   ########.fr       */
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
void	mlx_image_pixel_put(t_image *image, int x, int y, int color)
{
	int	*pixel;

	if (x >= 400 || y >= 400 || x < 0 || y < 0)
		return ;
	// without this condition the shape will be returned
	pixel = image->addr + (x * image->bpp / 8) + (y * image->line_len);
	*pixel = color; 
}

//====< clear_image >===========================================================
void	clear_image(t_image *image)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 400)
	{
		j = -1;
		while (++j < 400)
			mlx_image_pixel_put(image, i, j, 0);
	}
}
