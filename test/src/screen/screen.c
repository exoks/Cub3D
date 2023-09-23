/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:47:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/23 15:51:29 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "window.h"

void	render_screen(t_window *window)
{
	int	rays[400];

	int	i = -1;
	while (++i < 100)
		rays[i] = i;
	window->screen = create_image(window->mlx_ptr, 400, 400);
	int = -1;
	while (++i < 400)
	{
		200 + rays[i] * 10 / 400;
	}
}

