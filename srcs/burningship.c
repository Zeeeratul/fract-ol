/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:57:39 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/02 14:48:27 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burningship_calc(t_env *env)
{
	env->crd_re = env->x / env->zoom + env->x1 + env->right_left;
	env->crd_im = env->y / env->zoom + env->y1 + env->up_down;
	env->z_re = 0;
	env->z_im = 0;
	env->iter = 0;
	while (env->z_re * env->z_re + env->z_im * env->z_im < 4)
	{
		if (env->iter >= env->iter_max)
			break ;
		env->temp = env->z_re * env->z_re - env->z_im *
			env->z_im + env->crd_re;
		env->z_im = fabs(2 * env->z_im * env->z_re) + env->crd_im;
		env->z_re = env->temp;
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

void	*burningship(void *data)
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
			burningship_calc(env);
			env->y++;
		}
		env->x++;
	}
	return (env);
}
