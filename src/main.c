/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:31:15 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/11 21:21:17 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_pos	set_pos(t_pos pos)
{
	pos.zoom = 4.0;
	pos.x = 0.0;
	pos.y = 0.0;
	pos.m_x = -0.123;
	pos.m_y = 0.745;
	return (pos);
}

static t_env	*start_env(t_env *env, char *str)
{
	int			bpp;
	int			line;
	int			endian;

	bpp = 16;
	line = XMAX;
	endian = 0;
	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, XMAX, YMAX, "fractol");
	env->img = mlx_new_image(env->mlx, XMAX, YMAX);
	env->data = mlx_get_data_addr(env->img, &bpp, &line, &endian);
	env->choice = ft_atoi(str);
	env->pad_x = 0;
	env->pad_y = 0;
	env->max_iter = 5;
	env->pos = set_pos(env->pos);
	env->changed = 1;
	return (env);
}

int				main(int ac, char **av)
{
	t_env		*env;

	env = NULL;
	if (ac == 2 && ft_strequ(av[1], "help"))
		ft_help(av[0]);
	else if (!av[1] || ft_strlen(av[1]) != 1 ||
			!ft_strrchr("123", av[1][0]) || ac != 2)
		ft_puterror("Wrong usage. ./fractol help");
	env = start_env(env, av[1]);
	mlx_expose_hook(env->win, expose_hook, &env);
	mlx_mouse_hook(env->win, mouse_hook, &env);
	mlx_loop_hook(env->mlx, loop_hook, &env);
	print_fract(env);
	mlx_loop(env->mlx);
	return (0);
}