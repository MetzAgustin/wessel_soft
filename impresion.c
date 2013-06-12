/*
 * impresion.c
 *
 *  Created on: 03/06/2013
 *      Author: utnso
 */

#include "impresion.h"
#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

void imprimir (void* complejo, int forma) {

	if (forma==0) {	//hay que mostrar un BINOMICO

		complejoBin* x= malloc (sizeof (complejoBin));
		x= (complejoBin*)complejo;

		printf (" ( %f ; %f ) \n", x->real, x->imaginario);

	}

	if (forma==1) {	//hay que mostrar un POLAR

		complejoPol* o = malloc(sizeof(complejoPol));
		o = (complejoPol*) complejo;

		printf(" [%.2f;%.2f] \n", o->modulo, o->argumento);

	}
}


