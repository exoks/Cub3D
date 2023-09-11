/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:27:09 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/11 13:28:49 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __WINDOW_H__
# define __WINDOW_H__
# include "mlx.h"

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

#endif
