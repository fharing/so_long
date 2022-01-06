#ifndef SOLONG_H
# define SOLONG_H

//	INCLUDES

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

//	STRUCTS

typedef struct s_map
{
	int	e;
	int	p;
	int	c;
	int	x;
	int	y;
}				t_map;

typedef struct s_counter
{
	int	x;
	int	j;
	int	i;
	int	t;
	int	y;
}				t_counter;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*stone;
	void	*player;
	void	*wall;
	void	*exit;
	void	*collect;
	int		x;
	int		y;
	int		straw;
	int		steps;
	int		height;
	int		width;
	int		exitx;
	int		exity;
	int		collects[100][2];
	int		wallsmax;
	int		collectmax;
	int		walls[1000][2];
}				t_vars;

//	read input map and validate it
char	*ft_read_loop(int bytesred, char buff[2], int fd);
char	*ft_readmap(char *map);
void	ft_init_map(t_map *valid_map);
int		ft_validate_map(t_map *valid_map);
int		ft_lastline(char *map);
int		ft_check_walls(char *map);
int		ft_line_length(char *map, t_map *valid_map);
int		ft_check_letter(char *map, t_map *valid_map);
int		ft_checkmap(char *map, int *width, int *height);

//	create playboard
void	ft_putplayer(t_vars *vars, t_counter *count);
void	ft_putcollectable(t_vars *vars, t_counter *count);
void	ft_putexit(t_vars *vars, t_counter *count);
void	ft_putwalls(t_vars *vars, t_counter *count);
int		ft_put_images(char postition, t_vars *vars, t_counter *count);
int		ft_create_window(char *map, int width, int height);

//	get keystrokes and move player
int		ft_move_down(t_vars *vars);
int		ft_move_right(t_vars *vars);
int		ft_move_left(t_vars *vars);
int		ft_move_up(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

//	check for walls and collectables
int		ft_walls_yplus(t_vars *vars);
int		ft_walls_xplus(t_vars *vars);
int		ft_walls_xminus(t_vars *vars);
int		ft_walls_yminus(t_vars *vars);
int		ft_collect(t_vars *vars);

//	inititalize variables
void	ft_init_vars(t_vars *vars, int width, int height);
void	ft_init_counter(t_counter *count);

int		close_window(void);

#endif