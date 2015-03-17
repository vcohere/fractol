/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:31:25 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/17 13:48:22 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define XMAX		800
# define YMAX		600
# define XMAX_2		400
# define YMAX_2		300
# define MAX		500

typedef struct		s_pos
{
	float			zoom;
	float			x;
	float			y;
	float			m_x;
	float			m_y;
}					t_pos;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				choice;
	int				pad_x;
	int				pad_y;
	int				max_iter;
	int				changed;
	int				line;
	t_pos			pos;
}					t_env;

void				ft_help(char *str);
void				ft_puterror(char *str);
void				print_fract(t_env *env);
int					mouse_hook(int keypress, int x, int y, t_env *env);
int					loop_hook(t_env *env);
int					expose_hook(void *param);

#endif