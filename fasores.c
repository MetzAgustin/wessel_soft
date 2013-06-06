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

void operacion_suma_fasores () {

	printf ("Primer funcion: \n\n");
	func_trig f1= ingresar_funcion ();

	printf ("Segunda funcion: \n\n");
	func_trig f2= ingresar_funcion ();

	if (verificarFrecuencia (f1.frec, f2.frec)) {

		sumar_sinusoidales (f1,f2);

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

	printf (" %f %s (%f t + (%f)) \n\n",p.modulo,f.funcion,f.frec,p.argumento);

}
