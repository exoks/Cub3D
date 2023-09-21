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
	if (keycode == 102 || keycode == 106)
		window->player.alpha += 45.0;
	if (keycode == MOVE_UP || keycode == MOVE_DOWN)
		window->player.yp += ((MOVE_DOWN - keycode) * 4 - 2);
	if (keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		window->player.xp += -((MOVE_RIGHT - keycode) * 4 - 2);
	if (keycode >= MOVE_LEFT  && keycode <= MOVE_DOWN || keycode == 102)
	{
		clear_image(window->minimap);
		draw_grid(window, 20, 400);
		draw_rays(window);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->minimap->img, 0, 0);
	}
	return (0);
}
