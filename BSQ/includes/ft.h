#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

int		manage_map(char *file);
char	**manage_init(char *file, int *param);
int		check_map(char *buff, int *param);
char	**create_map(char *buff, int *param);
void	fill_map(char **map, int *param, char *buff);

char	**init_map(int x_max, int y_max);
int		init_param(char *buff, int *param);
char	*init_buff(char *file);
int		detect_y(char *buff, int *param);
int		detect_x(char *buff);

void	map_shading(int **mapint, int *param);
void	map_parsing(char **map, int *param);
int		**init_mapint(int x_max, int y_max);
void	search_sqrt(int **mapint, int *param, char **map);
void	map_writing(char **map, int *param, int x, int y);
void	print_map(char **map, int *param);

int		manage_stand(void);
char	*init_buffstand(void);
char	**manage_initstand(int *param);

#endif