/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:37:52 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/02 14:45:52 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol2(t_env *env)
{
	if (env->fractol_type == 1)
	{
		env->iter_max = 100;
		env->zoom = 300;
		env->x1 = -2.1;
		env->y1 = -1.2;
	}
	else if (env->fractol_type == 2)
	{
		env->iter_max = 100;
		env->zoom = 300;
		env->x1 = -1.7;
		env->y1 = -1.4;
		env->crd_re = -1.417022285618;
		env->crd_im = 0.0099534;
	}
	else if (env->fractol_type == 3 || env->fractol_type == 4)
	{
		env->iter_max = 100;
		env->zoom = 220;
		env->x1 = -2.2;
		env->y1 = -2.5;
	}
}

void	init_fractol(t_env *env)
{
	env->ptr = mlx_init();
	env->win = mlx_new_window(env->ptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	env->right_left = 0;
	env->up_down = 0;
	env->enable_zoom = 0;
	env->color_palette = 0;
	env->degrade_palette = 0;
	init_fractol2(env);
}

void	fractol(t_env *env)
{
	mlx_hook(env->win, 2, 1L < 0, &deal_key, env);
	mlx_hook(env->win, 6, 1L < 6, mouse_hook, env);
	mlx_mouse_hook(env->win, &deal_mouse, env);
	mlx_expose_hook(env->win, ft_expose_hook, env);
	mlx_loop(env->ptr);
}
