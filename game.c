#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int close_window(int keycode, void *param)
{
    if (keycode == 65307)
    {
        write(1,"Close Window",16);
        write(1,"\n",1);
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
        write(1,"Created Background",19);
        write(1,"\n",1);
        // vars->player.pos.x += 1;
    }
    else if (keycode == 0)
    {
        write(1,"Created Background",19);
        write(1,"\n",1);
        // vars->player.pos.x -= 1;
    }
    else if (keycode == 13)
    {
        write(1,"Created Background",19);
        write(1,"\n",1);
        // vars->player.pos.y -= 1;
    }
    else if (keycode == 1)
    {
        write(1,"Created Background",19);
        write(1,"\n",1);
        // vars->player.pos.y += 1;
    }
    return (0);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    // img
    void	*img;
    void	*img2;
	char	*relative_path = "assets/Background.xpm";
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
    write(1,"Created Window",15);
    write(1,"\n",1);
    // show images
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    write(1,"Created Background",19);
    write(1,"\n",1);
    img2 = mlx_xpm_file_to_image(mlx, relative_path2, &img_width2, &img_height2);
    mlx_put_image_to_window(mlx, mlx_win, img2, 1, 1);
    write(1,"Created objects",16);
    write(1,"\n",1);
    // key handler
    mlx_loop_hook(mlx_win,key_handler,&vars);
    // close window
    mlx_key_hook(mlx_win, close_window, mlx_win); 
    // finish loop
    mlx_loop(mlx);

    return (0);
}