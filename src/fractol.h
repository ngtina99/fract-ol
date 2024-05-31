/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:42:00 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 20:20:35 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PIXEL 600
# define ESCAPE_VALUE 4

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

// ERROR TESTING
// #define mlx_init() NULL
// #define mlx_new_window(x,d,t,y) NULL
// #define mlx_new_image(x,d,a) NULL
// #define mlx_get_data_addr(x,d,a,v) NULL

typedef struct s_data 
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	arg2;
	double	arg3;
	int		set;
	int		scheme;
	double	colorrange;
	int		red;
	int		green;
	int		blue;
	double	m_x;
	double	m_y;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		iter;
}				t_data;

typedef struct s_position
{
	double	a;
	double	b;
	double	x;
	double	y;
}				t_position;	

//KEYCODES
# define SPACE 32
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define FIVE 53
# define SIX 54
# define SEVEN 55
# define Z 122
# define X 120
# define W 119
# define S 115
# define A 97
# define D 100
# define R 114
# define G 103
# define B 98
# define I 105
# define O 111
# define ESC 65307
# define UP 65364
# define DOWN 65362
# define RIGHT 65363
# define LEFT 65361

//EVENTCODES
enum 
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int			main(int argc, char **argv);
void		setup_struct(t_data *img);
void		ft_hooks(t_data *img);
void		setup_fractol(t_data *img);
void		setup_image(t_data *img);
int			setup_mandelbrot(t_position c, t_data *img);
int			setup_julia(t_position value, t_data *img);
int			setup_tricorn(t_position c, t_data *img);
void		calculate_addr(t_data *data, int x, int y, int color);
void		red_scheme(int iteration, int x, int y, t_data *img);
void		green_scheme(int iteration, int x, int y, t_data *img);
void		blue_scheme(int iteration, int x, int y, t_data *img);
void		warhol_scheme(int iteration, int x, int y, t_data *img);
void		pastel_scheme(int iteration, int x, int y, t_data *img);
void		outline_scheme(int iteration, int x, int y, t_data *img);
void		psychedelic_scheme(int iteration, int x, int y, t_data *img);
double		ft_place(double value, double bottom, double top, double max);
int			ft_mousehooks(int keycode, int x, int y, t_data *img);
int			ft_keyhooks(int keycode, t_data *img);
int			close_window(t_data *img);
int			close_window_esc(int keycode, t_data *img);
void		print_message(int message_type);
void		print_error(int error_type, t_data *img);

#endif