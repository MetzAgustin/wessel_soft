/*
 * operaciones_polar.h
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#ifndef OPERACIONES_POLAR_H_
#define OPERACIONES_POLAR_H_

#include "definiciones.h"

complejoPol sumar_pol (complejoPol, complejoPol);
complejoPol restar_pol (complejoPol, complejoPol);
complejoPol multiplicar_pol (complejoPol, complejoPol);
complejoPol dividir_pol (complejoPol, complejoPol);
complejoPol potenciaNat_pol (complejoPol, int);
void raizN_esima_pol (complejoPol, int);

int mcd (int, int);

#endif /* OPERACIONES_POLAR_H_ */
