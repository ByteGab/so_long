#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int close_window(int keycode, void *param)
{
    // Cuando se presiona una tecla (por ejemplo ESC o el botón de cierre), se termina el programa
    if (keycode == 53)  // 65307 es el código para la tecla ESC
    {
        mlx_destroy_window(param, param);
        exit(0);  // Salir del programa
    }
    return (0);
}
int main(void)
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Paparoni esto es easy");

    // Usamos mlx_pixel_put para dibujar un píxel en la ventana directamente
    mlx_pixel_put(mlx, mlx_win, 20, 20, 0x00FF0000);

    mlx_loop(mlx);

    return 0;
}
