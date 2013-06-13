/*
 * operaciones_polar.c
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#include "operaciones_polar.h"
#include "operaciones_bin.h"
#include "conversion.h"
#include <stdio.h>

complejoPol sumar_pol (complejoPol x, complejoPol y) {

	complejoBin bin1 = convertPolarToBin (x);
	complejoBin bin2 = convertPolarToBin (y);

	complejoBin res_bin = sumar_bin (bin1, bin2);

	return (convertBinToPolar (res_bin));

}

complejoPol restar_pol (complejoPol x, complejoPol y) {

	complejoBin bin1 = convertPolarToBin (x);
	complejoBin bin2 = convertPolarToBin (y);

	complejoBin res_bin = restar_bin (bin1, bin2);

	return (convertBinToPolar (res_bin));

}


complejoPol multiplicar_pol (complejoPol x, complejoPol y) {

	complejoPol res;
	res.modulo = x.modulo * y.modulo;
	res.argumento = x.argumento + y.argumento;

	return res;

}

complejoPol dividir_pol (complejoPol x, complejoPol y) {

	complejoPol res;
	res.modulo = x.modulo / y.modulo;
	res.argumento = x.argumento - y.argumento;

	return res;

}

complejoPol potenciaNat_pol (complejoPol x, int potencia) {

	complejoPol res;
	res.modulo = pow (x.modulo, potencia);
	res.argumento = potencia * x.argumento;

	return res;


}

void raizN_esima_pol (complejoPol x, int rad){

	int i;

	double modulo = pow (x.modulo, 1.0/rad);

	for (i=0; i<rad; i++) {

		printf ("\n w(%d) = [%.3f;%.3f] \n", i, modulo, x.argumento/rad + 2*i*M_PI/rad);

	}

	printf ("\nRaices primitivas: \n");

	for (i = 1; i < rad; i++) {

		if (mcd(rad,i) == 1) {
			printf("\n w(%d) = [%.3f;%.3f] \n", i, modulo,x.argumento / rad + 2 * i * M_PI / rad);
		}
	}

}

int mcd (int a, int b) {

	int r;

	r = a % b;
	while (r > 0) {

		a = b;
		b = r;
		r = a % b;

	}

	return b;

}
