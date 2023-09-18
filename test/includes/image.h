/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:44:14 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/18 20:17:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __IMAGE_H__
# define __IMAGE_H__
# include <mlx.h>
# include <stdlib.h>

//******************************************************************************
//*          Structes|                                                         *
//******************************************************************************
typedef struct	s_image
{
	void		*img;
	int			hight;
	int			width;
	void		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_image;

//******************************************************************************
//*          Functions|                                                        *
//******************************************************************************
t_image	*create_image(void *mlx_ptr, int hight, int width);
void	mlx_image_pixel_put(t_image *image, int x, int y, int color);
void	clear_image(t_image *image);

#endif /*__IMAGE_H__*/
