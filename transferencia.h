/*
 * transferencia.h
 *
 *  Created on: 10/06/2013
 *      Author: utnso
 */

#ifndef TRANSFERENCIA_H_
#define TRANSFERENCIA_H_

#include "definiciones.h"

typedef struct {

	complejoBin ceros[10];
	int len_ceros;
	complejoBin polos [10];
	int len_polos;
	int k;

} func_trans;

func_trans ingreso_func_transferencia ();

#endif /* TRANSFERENCIA_H_ */
