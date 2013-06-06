/*
 * conversion.c
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#include "conversion.h"

double modulo (complejoBin x) {

	double argRaiz = pow(x.real,2) + pow(x.imaginario,2);
	double res = sqrt (argRaiz);


	return res;
}


complejoPol convertBinToPolar (complejoBin x) {


	complejoPol polar;

	polar.modulo = modulo (x);

	if (x.real!=0) {

		polar.argumento= atan (x.imaginario / x.real);

		if (determinarCuadrante (x) != 0) polar.argumento+= M_PI;

	} else {

		polar.argumento= M_PI_2; //o puede ser 3*M_PI_2 TODO;

	}

	return polar;

}

complejoBin convertPolarToBin (complejoPol p) {

	complejoBin x;

	x.real= p.modulo* cos (p.argumento);
	x.imaginario= p.modulo* sin (p.argumento);


	return x;
}

int determinarCuadrante (complejoBin x) {

	int cuad=0;

	if ((x.real < 0) & (x.imaginario < 0)) cuad= 1; //esta en el 2do cuadrante
	if ((x.real < 0) & (x.imaginario > 0)) cuad= 1;	//esta en el 3er cuadrante

	return cuad;
}

