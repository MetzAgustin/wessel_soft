/*
 * manejoDeIngreso.h
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#ifndef MANEJODEINGRESO_H_
#define MANEJODEINGRESO_H_

#include "operaciones_polar.h"
#include "operaciones_bin.h"
#include "definiciones.h"

#define FORMA_POLAR 1
#define FORMA_BINOMICA 0
#define ERROR_EN_INGRESO 2


void menu ();
void seleccion (char);
char seleccionarForma ();
parBin cargar_parBinom ();
parPol cargar_parPolar ();
complejoBin ingresarBinomico ();
complejoPol ingresarPolar ();




#endif /* MANEJODEINGRESO_H_ */
