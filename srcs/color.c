/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:02:04 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/21 11:17:31 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pixel_put(t_env *env, int x, int y)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		env->img_data[(x * (env->bpp / 8)) +
			(y * env->size_l)] = env->blue;
		env->img_data[(x * (env->bpp / 8)) +
			(y * env->size_l) + 1] = env->green;
		env->img_data[(x * (env->bpp / 8)) +
			(y * env->size_l) + 2] = env->red;
	}
}

void	color_interior(t_env *env)
{
	if (env->color_palette == 1)
	{
		env->red = 0;
		env->green = 0;
		env->blue = 0;
	}
	else if (env->color_palette == 0)
	{
		env->red = 0;
		env->green = 255;
		env->blue = 0;
	}
	else if (env->color_palette == 2)
	{
		env->red = 0;
		env->green = 249;
		env->blue = 255;
	}
	else if (env->color_palette == 3)
	{
		env->red = 255;
		env->green = 0;
		env->blue = 0;
	}
}

void	color_exterior(t_env *env)
{
	if (env->degrade_palette == 1)
	{
		env->red = 5 * env->iter;
		env->green = 5 * env->iter;
		env->blue = 5 * env->iter;
	}
	else if (env->degrade_palette == 0)
	{
		env->red = 0;
		env->green = 10 * env->iter;
		env->blue = 2 * env->iter;
	}
	else if (env->degrade_palette == 2)
	{
		env->red = 0;
		env->green = 10 * env->iter;
		env->blue = 10 * env->iter;
	}
	else if (env->degrade_palette == 3)
	{
		env->red = 10 * env->iter;
		env->green = 0;
		env->blue = 1 * env->iter;
	}
}
