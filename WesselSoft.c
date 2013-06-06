/*
 * WesselSoft.c
 *
 *  Created on: 03/06/2013
 *      Author: utnso
 */
#include <stdio.h>
#include "manejoDeIngreso.h"


int main (void) {

	char op;

	printf ("WesselSoft: Operaciones con Complejos\n\n");

	while (1) {

		op=0;

		menu ();

		scanf("%c", &op);
		while(getchar()!='\n');

		seleccion (op);
	}

	return 0;
}
