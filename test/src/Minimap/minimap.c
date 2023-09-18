/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:51:19 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/18 19:58:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "minimap.h"
# include <stdio.h>
//====< create_minimap >========================================================
int	create_minimap(t_window *window)
{
	window->minimap = create_image(window->mlx_ptr, 400, 400);
	printf("minimap => %p\n", window->minimap);
	return (0);
}

//====< draw_ray >==============================================================
//int	draw_ray()
//{
//	
//}
