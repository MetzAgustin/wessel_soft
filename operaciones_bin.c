/*
 * operaciones.c
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#include "operaciones_bin.h"
#include "conversion.h"
#include "operaciones_polar.h"
#include "WesselSoft.h"
#include <math.h>
#include <stdio.h>

double real (complejoBin x){

	return x.real;

}
double imagin (complejoBin x){

	return x.imaginario;

}

complejoBin sumar_bin (complejoBin a, complejoBin b) {

	complejoBin resultado;

	resultado.real = a.real + b.real;
	resultado.imaginario= a.imaginario + b.imaginario;

	return resultado;

}

complejoBin restar_bin (complejoBin a, complejoBin b) {

	complejoBin resultado;

	resultado.real = a.real - b.real;
	resultado.imaginario= a.imaginario - b.imaginario;

	return resultado;

}

complejoBin multiplicar_bin (complejoBin a, complejoBin b) {

	complejoBin resultado;

	resultado. real= (a.real * b.real) - (a.imaginario * b.imaginario);
	resultado. imaginario= (a.real * b.imaginario) + (a.imaginario * b.real);

	return resultado;

}

complejoBin conjugado (complejoBin x) {

	complejoBin conj= x;
	conj.imaginario= -(x.imaginario);

	return conj;
}

complejoBin dividir_bin (complejoBin a, complejoBin b) {

	complejoBin resultado;

	resultado.real= real (multiplicar_bin (a, conjugado (b))) / pow (modulo (b), 2);
	resultado.imaginario= imagin (multiplicar_bin (a, conjugado (b))) / pow (modulo (b), 2);

	return resultado;
}

complejoBin potenciaNat_bin (complejoBin x, int potencia){


	complejoPol res_polar = potenciaNat_pol (convertBinToPolar (x), potencia);



	return (convertPolarToBin (res_polar));
}

void raizN_esima_bin (complejoBin x, int rad){

	if (rad!=2){

		raizN_esima_pol (convertBinToPolar (x), rad);

	} else {

		raizCuadrada_bin (x);

	}
}

void raizCuadrada_bin (complejoBin x){

	double r1,rMenos1,r2,rMenos2;

	r1= sqrt ((modulo (x)+ x.real)/2.0);
	rMenos1= -r1;

	r2= sqrt ((modulo (x)- x.real)/2.0);
	rMenos2= -r2;


	if (x.imaginario>0) {


		printf ("U = (%.2f;%.2f)  v  U = (%.2f;%.2f)\n",r1,r2,rMenos1,rMenos2);

	}

	if (x.imaginario<0) {


		printf ("U = (%.2f;%.2f)  v  U = (%.2f;%.2f)\n",r1,rMenos2,rMenos1,r2);

	}




}
