/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:16:10 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/02 14:45:04 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	menu2(t_env *env)
{
	char *iter_max;
	char *palette;
	char *degrade;

	iter_max = ft_itoa(env->iter_max);
	palette = ft_itoa(env->color_palette);
	degrade = ft_itoa(env->degrade_palette);
	mlx_string_put(env->ptr, env->win, 110, 10, 0xFFFFFF, iter_max);
	mlx_string_put(env->ptr, env->win, 190, 750, 0xFFFFFF, palette);
	mlx_string_put(env->ptr, env->win, 190, 770, 0xFFFFFF, degrade);
	free(iter_max);
	free(palette);
	free(degrade);
	mlx_string_put(env->ptr, env->win, 500, 750, 0xFFFFFF,
			"Press R for interior color");
	mlx_string_put(env->ptr, env->win, 500, 770, 0xFFFFFF,
			"Press T for exterior color");
	mlx_string_put(env->ptr, env->win, 630, 10, 0xFF0000, "Escape for exit");
}

void	menu(t_env *env)
{
	mlx_string_put(env->ptr, env->win, 10, 10, 0xFFFFFF, "Iteration");
	mlx_string_put(env->ptr, env->win, 10, 750, 0xFFFFFF, "Palette interieur");
	mlx_string_put(env->ptr, env->win, 10, 770, 0xFFFFFF, "Palette degrade");
	if (env->enable_zoom == 0 && env->fractol_type == 2)
	{
		mlx_string_put(env->ptr, env->win, 500, 710, 0xFFFFFF,
				"Press E for mouse variation");
		mlx_string_put(env->ptr, env->win, 500, 730, 0xFF0000,
				"Mouse not activated");
	}
	else if (env->enable_zoom == 1 && env->fractol_type == 2)
	{
		mlx_string_put(env->ptr, env->win, 500, 710, 0xFFFFFF,
				"Press E for mouse variation");
		mlx_string_put(env->ptr, env->win, 500, 730, 0x00FF00,
				"Mouse activated");
	}
	menu2(env);
}

void	create_thread(t_env *env)
{
	t_env		copy[THREAD];
	pthread_t	t[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		ft_memcpy((void*)&copy[i], (void*)env, sizeof(t_env));
		copy[i].y = i * 5;
		copy[i].y_max = (i + 1) * 5;
		if (env->fractol_type == 1)
			pthread_create(&t[i], NULL, mandelbrot, &copy[i]);
		else if (env->fractol_type == 2)
			pthread_create(&t[i], NULL, julia, &copy[i]);
		else if (env->fractol_type == 3)
			pthread_create(&t[i], NULL, burningship, &copy[i]);
		else if (env->fractol_type == 4)
			pthread_create(&t[i], NULL, bonus, &copy[i]);
		i++;
	}
	while (i--)
	{
		pthread_join(t[i], NULL);
	}
}

int		ft_expose_hook(t_env *env)
{
	env->img_ptr = mlx_new_image(env->ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img_data = mlx_get_data_addr(env->img_ptr, &(env->bpp),
			&(env->size_l), &(env->endian));
	create_thread(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img_ptr, 0, 0);
	menu(env);
	mlx_destroy_image(env->ptr, env->img_ptr);
	return (0);
}
