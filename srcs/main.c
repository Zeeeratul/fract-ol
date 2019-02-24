/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:38:02 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/02 15:00:13 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		check_arg(char *arg, t_env *env)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
	{
		env->fractol_type = 1;
		return (0);
	}
	else if (ft_strcmp(arg, "julia") == 0)
	{
		env->fractol_type = 2;
		return (0);
	}
	else if (ft_strcmp(arg, "burningship") == 0)
	{
		env->fractol_type = 3;
		return (0);
	}
	else if (ft_strcmp(arg, "bonus") == 0)
	{
		env->fractol_type = 4;
		return (0);
	}
	else
		ft_putstr("arguments: 'mandelbrot', 'julia', 'burningship', 'bonus'\n");
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putstr("1 argument needed\n");
		ft_putstr("arguments: 'mandelbrot', 'julia', 'burningship', 'bonus'\n");
		return (-1);
	}
	if (check_arg(argv[1], &env) == -1)
		return (-1);
	init_fractol(&env);
	fractol(&env);
	return (0);
}
