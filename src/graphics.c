/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:14:20 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/17 13:48:40 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_to_img(int res, t_env *env, t_coord p)
{
	int			color;

	ft_putnbr(p.y * env->line + 4 * p.x);
	ft_putendl("");
	if (res == MAX)
	{
		color = mlx_get_color_value(env->mlx, 0x000000) & 0xFFFFFFFF;
		env->data[p.y * env->line + 4 * p.x] = color;
	}
	else
	{
		color = mlx_get_color_value(env->mlx, res * 8) & 0xFFFFFFFF;
		env->data[p.y * env->line + 4 * p.x] = color;
	}
}

int				calc_mandelbrot(t_coord p, t_env *env, int res)
{
	double		c_real;
	double		c_i;
	double		x;
	double		y;
	double		tmp_x;

	res = 0;
	x = 0;
	y = 0;
	c_real = ((p.x - XMAX_2 + env->pos.x) * env->pos.zoom) / XMAX;
	c_i = ((p.y - YMAX_2 + env->pos.y) * env->pos.zoom) / XMAX;
	while (((x * x) + (y * y)) < 4 && res < MAX)
	{
		tmp_x = (x * x) - (y * y) + c_real;
		y = (2 * x * y) + c_i;
		x = tmp_x;
		res++;
	}
	return (res);
}

int				calc_julia(t_coord p, t_env *env, int res)
{
	double		c_real;
	double		c_i;
	double		x;
	double		y;
	double		tmp_x;

	res = 0;
	x = ((p.x - XMAX_2 + env->pos.x) * env->pos.zoom) / XMAX;
	y = ((p.y - YMAX_2 + env->pos.y) * env->pos.zoom) / XMAX;
	c_real = env->pos.m_x;
	c_i = env->pos.m_y;
	while (((x * x) + (y * y)) < 4 && res < MAX)
	{
		tmp_x = (x * x) - (y * y) + c_real;
		y = (2 * x * y) + c_i;
		x = tmp_x;
		res++;
	}
	return (res);
}

int				calc_ship(t_coord p, t_env *env, int res)
{
	double		c_real;
	double		c_i;
	double		x;
	double		y;
	double		tmp_x;

	res = 0;
	x = 0;
	y = 0;
	c_real = ((p.x - XMAX_2 + env->pos.x) * env->pos.zoom) / XMAX;
	c_i = ((p.y - YMAX_2 + env->pos.y) * env->pos.zoom) / XMAX;
	while (((x * x) + (y * y)) < 4 && res < MAX)
	{
		tmp_x = (x * x) - (y * y) + c_real;
		y = -((2 * x * y) + c_i);
		x = tmp_x;
		res++;
	}
	return (res);
}

void			print_fract(t_env *env)
{
	t_coord		p;
	int			res;

	p.x = 0;
	p.y = 0;
	while (p.y < YMAX)
	{
		p.x = 0;
		while (p.x < XMAX)
		{
			if (env->choice == 1)
				res = calc_mandelbrot(p, env, res);
			else if (env->choice == 2)
				res = calc_julia(p, env, res);
			else
				res = calc_ship(p, env, res);
			put_to_img(res, env, p);
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_putendl("\n");
}