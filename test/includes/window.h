/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:27:09 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/22 18:39:26 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __WINDOW_H__
# define __WINDOW_H__
# include "image.h"

//******************************************************************************
//*         Structes|                                                          *
//******************************************************************************
typedef struct	s_player
{
	float	xp;
	float	yp;
	float	fv;
	float	dir;
	int	alpha;
}				t_player;

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			hight;
	int			width;
	t_image		*minimap;
	t_player	player;
	t_image		*screen;
}				t_window;

//******************************************************************************
//*         Functions|                                                         *
//******************************************************************************
int	create_window(t_window *win);

void	draw_grid(t_window *window, int step, int w);
int		draw_ray(t_window *window, float xr, float yr);
int		draw_rays(t_window *window);
void	player_init(t_player *player);
#endif /*__WINDOW_H__*/
