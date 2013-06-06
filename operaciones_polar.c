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

		printf ("\n w(%d) = [ %f ; %f ] \n", i, modulo, x.argumento/rad + 2*i*M_PI/rad);

	}

}
