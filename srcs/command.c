/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:04:54 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/17 16:36:09 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_hook(int x, int y, t_env *env)
{
	if (env->enable_zoom == 1)
	{
		if (env->fractol_type == 2)
		{
			env->crd_re = x * 2;
			env->crd_im = y * 2;
			ft_expose_hook(env);
		}
	}
	return (0);
}

void	color_change(int key, t_env *env)
{
	if (key == 15)
	{
		env->color_palette++;
		if (env->color_palette == 4)
			env->color_palette = 0;
	}
	else if (key == 17)
	{
		env->degrade_palette++;
		if (env->degrade_palette == 4)
			env->degrade_palette = 0;
	}
}

void	ft_move(int key, t_env *env)
{
	if (key == 123)
		env->right_left -= (10 / env->zoom);
	else if (key == 124)
		env->right_left += (10 / env->zoom);
	else if (key == 125)
		env->up_down += (10 / env->zoom);
	else if (key == 126)
		env->up_down -= (10 / env->zoom);
}

int		deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 78)
	{
		env->iter_max -= 10;
		if (env->iter_max <= 0)
			env->iter_max = 0;
	}
	else if (key == 69)
		env->iter_max += 10;
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(key, env);
	else if (key == 15 || key == 17)
		color_change(key, env);
	else if (key == 14)
		env->enable_zoom = !env->enable_zoom;
	ft_expose_hook(env);
	return (0);
}

int		deal_mouse(int mousecode, int x, int y, t_env *env)
{
	if (mousecode == 4)
	{
		env->x1 = (x / env->zoom) - (x / (env->zoom * 1.2)) + env->x1;
		env->y1 = (y / env->zoom) - (y / (env->zoom * 1.2)) + env->y1;
		env->zoom *= 1.2;
		env->iter_max++;
	}
	else if (mousecode == 5)
	{
		if (env->iter_max - 1 <= 0)
			env->iter_max = 0;
		else
		{
			env->x1 = (x / env->zoom) - (x / (env->zoom / 1.2)) + env->x1;
			env->y1 = (y / env->zoom) - (y / (env->zoom / 1.2)) + env->y1;
			env->zoom /= 1.2;
			env->iter_max--;
		}
	}
	ft_expose_hook(env);
	return (0);
}
