#include "so_long.h"

int check_map(int maps,t_map *map_data,char *map,t_vars *vars)
{
    // existe el archivo del mapa?
    if (maps != 2)
	{
		if (maps == 1)
			printf("Error añade un mapa\n");
		else
			printf("Error añade un solo mapa\n");
        return (0);
	}
	read_map(map, &vars);
    // el mapa es rectangular?
	map_data->check_rectangular = 0;
    if (map_data->check_rectangular == 1)
    {
        printf("Error el mapa no es rectangular\n");
        return (0);
    }
	// el mapa esta cerrado por paredes?
	map_data->check_walls = 0;
	if (map_data->check_walls == 1)
	{
		printf("Error el mapa no esta cerrado por paredes\n");
        return (0);
	}
	// solo puede tener una salida
	map_data->check_exit = 0;
	if (map_data->check_exit == 1)
	{
		printf("Error el mapa no tiene una salida correcta\n");
        return (0);
	}
	// solo puede tener una posición inicial
	map_data->check_player = 0;
	if (map_data->check_player == 1)
	{
		printf("Error el mapa no tiene una posición inicial correcta\n");
        return (0);
	}
	/*
	  - debe tener al menos un coleccionable:
	  	- solo se podra salir cuando esten todo los coleccionables recolectados.
		- tener un algoritmo para comprobar a principio si se puede salir y otro para cuando se quiera salir.
	*/
	map_data->check_coins = 0;
	if (map_data->check_coins == 1)
	{
		printf("Error el mapa no tiene al menos una coleccionable\n");
        return (0);
	}
    else
	{
        return (1);
	}
}