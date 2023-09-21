/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:52:46 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/20 16:06:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __EVENTS_H__
# define __EVENTS_H__
# include "window.h"
# include <math.h>
# define MOVE_UP	65362
# define MOVE_DOWN	65364
# define MOVE_LEFT	65361
# define MOVE_RIGHT	65363

int	events(int keycode, t_window *window);
#endif /*__EVENTS_H__*/
