#include "minilibx-linux/mlx.h"

int     main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Paparoni esto es easy");
    mlx_loop(mlx);
}