/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:48:47 by cdelahay          #+#    #+#             */
/*   Updated: 2019/01/02 14:48:41 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define THREAD 160

typedef struct	s_env
{
	void		*ptr;
	void		*win;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_l;
	int			endian;
	int			iter;
	int			iter_max;
	int			x;
	int			y;
	int			y_max;
	int			fractol_type;
	int			red;
	int			green;
	int			blue;
	int			color_palette;
	int			degrade_palette;
	int			enable_zoom;
	double		zoom;
	double		crd_re;
	double		crd_im;
	double		z_re;
	double		z_im;
	double		temp;
	double		x1;
	double		y1;
	float		right_left;
	float		up_down;
}				t_env;

void			fractol(t_env *env);
void			init_fractol(t_env *env);
int				deal_key(int key, t_env *env);
int				deal_mouse(int mousecode, int x, int y, t_env *env);
int				mouse_hook(int x, int y, t_env *env);
int				ft_expose_hook(t_env *env);
void			ft_pixel_put(t_env *env, int x, int y);
void			ft_move(int key, t_env *env);
void			*mandelbrot(void *data);
void			*julia(void *data);
void			*burningship(void *data);
void			*bonus(void *data);
void			color_interior(t_env *env);
void			color_exterior(t_env *env);

#endif
