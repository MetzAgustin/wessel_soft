/*
 * operaciones_binario.h
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#ifndef OPERACIONES_BIN_H_
#define OPERACIONES_BIN_H_

#include "definiciones.h"

double real (complejoBin);
double imagin (complejoBin);
complejoBin sumar_bin (complejoBin, complejoBin);
complejoBin restar_bin (complejoBin, complejoBin);
complejoBin multiplicar_bin (complejoBin, complejoBin);
complejoBin conjugado (complejoBin);
complejoBin dividir_bin (complejoBin, complejoBin);
complejoBin potenciaNat_bin (complejoBin, int);
void raizN_esima_bin (complejoBin, int);
void raizCuadrada_bin (complejoBin);










#endif /* OPERACIONES_BIN_H_ */
