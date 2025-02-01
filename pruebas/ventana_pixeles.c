#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int close_window(int keycode, void *param)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}
int main(void)
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "Paparoni esto es easy");

    mlx_pixel_put(mlx, mlx_win, 20, 20, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 21, 20, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 22, 20, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 23, 20, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 24, 20, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 20, 21, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 20, 22, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 20, 23, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 20, 24, 0x00FF0000);
    mlx_key_hook(mlx_win, close_window, mlx_win); 

    mlx_loop(mlx);

    return 0;
}
