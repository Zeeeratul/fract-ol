/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:57:44 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/17 16:15:21 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_calc(t_env *env)
{
	env->z_re = env->x / env->zoom + env->x1 + env->right_left;
	env->z_im = env->y / env->zoom + env->y1 + env->up_down;
	env->iter = 0;
	while (env->z_re * env->z_re + env->z_im * env->z_im < 4)
	{
		if (env->iter >= env->iter_max)
			break ;
		env->temp = env->z_re;
		env->z_re = env->z_re * env->z_re - env->z_im *
			env->z_im + (env->crd_re - 800) / WIN_WIDTH;
		env->z_im = 2 * env->z_im * env->temp +
			(env->crd_im - 800) / WIN_HEIGHT;
		env->iter++;
	}
	if (env->iter == env->iter_max)
	{
		color_interior(env);
		ft_pixel_put(env, env->x, env->y);
	}
	else
	{
		color_exterior(env);
		ft_pixel_put(env, env->x, env->y);
	}
}

void	*julia(void *data)
{
	t_env	*env;
	int		temp;

	env = (t_env*)data;
	env->x = 0;
	temp = env->y;
	while (env->x < WIN_WIDTH)
	{
		env->y = temp;
		while (env->y < env->y_max)
		{
			julia_calc(env);
			env->y++;
		}
		env->x++;
	}
	return (env);
}
