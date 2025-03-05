#include "so_long.h"

// el mapa esta cerrado por paredes?
	// solo puede tener una salida
	// solo puede tener una posición inicial
	/*
	  - debe tener al menos un coleccionable:
	  	- solo se podra salir cuando esten todo los coleccionables recolectados.
		- tener un algoritmo para comprobar a principio si se puede salir y otro para cuando se quiera salir.
	*/
int check_map(int map)
{
    t_map map_data;
    // existe el archivo del mapa?
    if (map != 2)
	{
		if (map == 1)
			printf("Error añade un mapa\n");
		else
			printf("Error añade un solo mapa\n");
        return (0);
	}
    // el mapa es rectangular?
    else if (map_data.rectangular == 1)
    {
        printf("Error el mapa no es rectangular\n");
        return (0);
    }
    else
        return (1);
}
// prueba 5