/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:47:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/24 13:52:19 by oezzaou          ###   ########.fr       */
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

	int	i = -1;
	while (++i < 400)
	{
		rays[i] = 200;
//		if (i < 100)
//			rays[i] = i;
//		if (i >= 100 && i < 200)
//			rays[i] = 200;
//		if (i >= 200 && i < 400)
//			rays[i] = 400 - i;
	}
	window->screen = create_image(window->mlx_ptr, 400, 400);
	i = -1;
	while (++i < 400)
	{
		y = (rays[i] * (64 / 400 - 1) + 400);
		int	j = 200 - (y / 2);
		while (++j <= (200 + (y / 2)))
			mlx_image_pixel_put(window->screen, i, j, 255 << 16);
	}
}

