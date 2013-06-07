/*
 * fasores.c
 *
 *  Created on: 24/04/2013
 *      Author: utnso
 */

#include <stdio.h>
#include "fasores.h"
#include "conversion.h"
#include "operaciones_bin.h"
#include <math.h>
#include <string.h>

void operacion_suma_fasores () {

	printf ("\nPrimer funcion: \n\n");
	func_trig f1= ingresar_funcion ();

	printf ("\nSegunda funcion: \n\n");
	func_trig f2= ingresar_funcion ();


	if (verificarFrecuencia (f1.frec, f2.frec)) {

		pasaje_entre_func (&f1, &f2);

		sumar_sinusoidales (f1,f2);

	}

}

void pasaje_entre_func (func_trig* f1, func_trig* f2) {

	if (strcmp(f1->funcion, f2->funcion)!=0) {

		if (strcmp(f1->funcion, "sen")==0) {

			strcpy (f2->funcion,"sen");
			f2->fase = f2->fase + (M_PI / 2);

		}

		if (strcmp(f2->funcion, "sen")==0) {

			strcpy (f1->funcion,"sen");
			f1->fase = f1->fase + (M_PI / 2);

		}

	}
}


func_trig ingresar_funcion () {

	func_trig f;

	printf ("Ingrese función (sen/cos): ");
	scanf ("%s", f.funcion);
	while(getchar()!='\n');

	printf ("Ingrese amplitud: ");
	scanf ("%lf", &f.amplitud);
	while(getchar()!='\n');

	printf ("Ingrese frecuencia: ");
	scanf ("%lf", &f.frec);
	while(getchar()!='\n');

	printf ("Ingrese fase: ");
	scanf ("%lf", &f.fase);
	while(getchar()!='\n');

	return f;
}

int verificarFrecuencia (double f1, double f2){

	if (f1==f2) return 1;	//esta bien
	else {

		printf ("Las funciones tienen diferente frecuencia\n\n");
		return 0;			// no se podra realizar
	}

}

void sumar_sinusoidales (func_trig f, func_trig g) {

	complejoBin x,y,z;
	complejoPol p;

	x.real= f.amplitud * cos (f.fase);
	x.imaginario= f.amplitud * sin (f.fase);

	y.real= g.amplitud * cos (g.fase);
	y.imaginario= g.amplitud * sin (g.fase);

	z= sumar_bin (x,y);

	p= convertBinToPolar (z);

	printf ("\nResultado: %f %s (%f t + (%f)) \n\n",p.modulo,f.funcion,f.frec,p.argumento);

}
