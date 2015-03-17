/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <vcohere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:38:03 by vcohere           #+#    #+#             */
/*   Updated: 2015/03/17 11:20:47 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_help(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <choice>");
	ft_putendl("    1 - Mandelbrot");
	ft_putendl("    2 - Julia");
	ft_putendl("    3 - Tricorn (Derivate of Mandelbrot)");
	exit(0);
}

void				ft_puterror(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}