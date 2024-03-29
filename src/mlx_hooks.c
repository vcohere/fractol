/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:46:41 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/17 11:45:58 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose_hook(void *param)
{
	(void)param;
	return (0);
}

int				loop_hook(t_env *env)
{
	if (env->changed == 1)
	{
		ft_bzero(env->data, 1919996);
		env->changed = 0;
		print_fract(env);
	}
	return (0);
}

int				mouse_hook(int keypress, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (keypress == 4)
		env->pos.zoom /= 1.2;
	else if (keypress == 5)
		env->pos.zoom *= 1.2;
	env->changed = 1;
	return (0);
}