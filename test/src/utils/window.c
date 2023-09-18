/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:46:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/18 12:49:40 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <mlx.h>
# include "window.h"

//====< create_win >============================================================
int	create_window(t_window *win)
{
	win->hight = 400;
	win->width = 400;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (0);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->hight, win->width, "T");
	return (1);
}
