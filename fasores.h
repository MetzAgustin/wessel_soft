/*
 * fasores.h
 *
 *  Created on: 24/04/2013
 *      Author: utnso
 */

#ifndef FASORES_H_
#define FASORES_H_

#include "definiciones.h"

typedef struct {

	char funcion [3];
	double amplitud;
	double frec;
	double fase;

} func_trig;

typedef struct {

	double nro;
	double exp_e; //exponente al que esta elevado E: E^i..

} fasor;

void operacion_suma_fasores ();

int verificarFrecuencia (double, double);

void sumar_sinusoidales (func_trig, func_trig);

fasor obtenerFasor (func_trig);

func_trig ingresar_funcion ();

void pasaje_entre_func (func_trig*, func_trig*);

#endif /* FASORES_H_ */
