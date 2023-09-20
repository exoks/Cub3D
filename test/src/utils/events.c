/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:51:23 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/20 20:00:07 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "events.h"
# include <stdio.h>
int	events(int keycode, t_window *window)
{
//	printf("keycode| ==> %d\n", keycode);
	if (keycode == 38)
		printf("rotate ...\n");
	if (keycode == MOVE_UP || keycode == MOVE_DOWN)
		window->player.yp += ((126 - keycode) * 4 - 2);
	if (keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		window->player.xp += -((124 - keycode) * 4 - 2);
	if (keycode >= 123 && keycode <= 126)
	{
		clear_image(window->minimap);
		draw_grid(window, 20, 400);
		draw_rays(window);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->minimap->img, 0, 0);
	}
	return (0);
}
