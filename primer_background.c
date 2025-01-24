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
    // img
    void	*img;
	char	*relative_path = "assets/Background.xpm";
	int		img_width;
	int		img_height;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "Paparoni esto es easy");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    mlx_key_hook(mlx_win, close_window, mlx_win); 

    mlx_loop(mlx);

    return 0;
}
