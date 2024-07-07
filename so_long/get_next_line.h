/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:42 by inkahar           #+#    #+#             */
/*   Updated: 2024/04/07 03:53:47 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				i;
	int				j;
	struct s_stack	*next;
}					t_stack;

typedef struct s_check
{
	int				player;
	int				exit;
	int				collect;
}					t_check;

typedef struct s_map
{
	char			**map;
	int				length;
	int				width;
	int				x;
	int				y;
	int				w;
	int				p;
	int				c;
	int				e;
	int				pi;
	int				pj;
	int				rc;
	int				valid;
	int				img_width;
	int				img_height;
	void			*mlx;
	void			*win;
	int				step;
	int				move_count;
	void			*player;
	void			*collect;
	void			*road;
	void			*wall;
	void			*exit;
	t_stack			*visited;
}					t_map;

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define X_NO_EVENT_MASK 0
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

int					berchk(char *a);
void				so_long(char *file);
void				init_map(t_map *map);
void				mapy(t_map *game, char *filename);
int					parse(t_map *map, t_map m);
char				*get_next_line(int fd);
size_t				ft_strlen(char const *str);
char				*ft_strchr(char const *str, int c);
char				*ft_strdup(char const *src);
char				*ft_strjoin(char const *s1, char const *s2);

int					charnum(t_map *map_array);
void				numchar(size_t *p, size_t *e, size_t *c, t_map *map);
int					is_valid_map_structure(t_map *map_array, t_map dimensions);
int					noku(char map);
int					border(t_map *map, t_map lb);

void				mapbfs(t_map *map);
t_stack				*create_node(t_stack **stack, int i, int j);
void				check_path(t_map *map, int i, int j, t_stack **visited);
int					isv(t_stack *s, int x, int y);

void				intimg(t_map *map);
void				*load(t_map *map, char *a);
int					img_put(t_map *map);
void				paint(t_map *map, int i, int j);
int					key_press(int keycode, t_map *map);
void				playerxy(t_map *map);

int					ft_printf(const char *format, ...);
void				put_digit(long long int num, int base, int *len);
void				put_str(char *str, int *len);

void				free_map(char **map);
void				exit_error(t_map *map);

#endif