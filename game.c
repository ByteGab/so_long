#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int close_window(int keycode, void *param)
{
    if (keycode == 65307)
    {
        printf("Close Window\n");
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
int key_handler(int keycode, t_vars *vars)
{
    if (keycode == 2)
    {
        printf("Key W\n");
        // vars->player.pos.x += 1;
    }
    else if (keycode == 0)
    {
        printf("Key S\n");
        // vars->player.pos.x -= 1;
    }
    else if (keycode == 13)
    {
        printf("Key A\n");
        // vars->player.pos.y -= 1;
    }
    else if (keycode == 1)
    {
        printf("Key D\n");
        // vars->player.pos.y += 1;
    }
    return (0);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    // img
    void	*background_img;
    void	*img2;
	char	*relative_path_background = "assets/Background.xpm";
    char	*relative_path2 = "assets/platforms.xpm";
	int		img_width;
	int		img_height;
    int		img_width2;
	int		img_height2;

    // key handler
    t_vars	vars;

    mlx = mlx_init();
    // open window
    mlx_win = mlx_new_window(mlx, 928, 793, "Paparoni esto es easy");
    printf("Created Window\n");
    // show images
    // background
    background_img = mlx_xpm_file_to_image(mlx, relative_path_background, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, background_img, 0, 0);
    printf("Created Background\n");
    // walls
    img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width2, &img_height2);
    mlx_put_image_to_window(mlx, mlx_win, img2, 1, 1);
    printf("Created walls\n");
    // key handler
    mlx_loop_hook(mlx_win,key_handler,&vars);
    // close window
    mlx_key_hook(mlx_win, close_window, mlx_win); 
    // finish loop
    mlx_loop(mlx);
    //  cc game.c libmlx_Linux.a -lX11 -lXext -o game 
    return (0);
}