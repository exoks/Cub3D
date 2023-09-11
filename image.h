/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:44:14 by oezzaou           #+#    #+#             */
/*   Updated: 2023/09/11 14:50:33 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef __IMAGE_H__
# define __IMAGE_H__

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			pixel_bits;
	int			endian_mode;
	int			line_bytes;
}				t_image;

#endif

