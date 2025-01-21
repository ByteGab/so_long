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
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Paparoni esto es easy");

    mlx_pixel_put(mlx, mlx_win, 20, 20, 0x00FF0000);
    mlx_key_hook(mlx_win, close_window, mlx_win); 

    mlx_loop(mlx);

    return 0;
}
