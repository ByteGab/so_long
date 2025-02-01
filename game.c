/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/01 21:42:22 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


int main(void)
{
    void *mlx;
    void *mlx_win;
    // img
    void	*background_img;
    void	*img2;
	char	*relative_path_background = "assets/Background.xpm";
    char	*relative_path2 = "assets/4b.xpm";
	int		img_width;
	int		img_height;
    int		img_width2;
	int		img_height2;
    int     i;
    int     z;

    i = 60;

    
    // read_map
    read_map();
    // key handler
    
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
    while (i > 0)
    {
        mlx_put_image_to_window(mlx, mlx_win, img2, (i * 16),1);
        i--;
    }
    printf("Created walls\n");
    // close window
    mlx_key_hook(mlx_win, close_window, mlx_win);
    
    // finish loop
    mlx_loop(mlx);
    //  cc game.c libmlx_Linux.a -lX11 -lXext -o game 
    return (0);
}