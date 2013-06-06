/*
 * definiciones.h
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#ifndef DEFINICIONES_H_
#define DEFINICIONES_H_

typedef struct {

	double phi;
	double tita;
	int signo_im; /*1= negativo; 0=positivo*/

} complejoExp;

typedef struct {

	double phi;
	double cos;
	double sen;
	int signo_im;

} complejoTrig;


typedef struct {

	double real;
	double imaginario;

} complejoBin;

typedef struct {

	complejoBin comp1;
	complejoBin comp2;

} parBin;

typedef struct {

	double modulo;
	double argumento;

} complejoPol;

typedef struct {

	complejoPol comp1;
	complejoPol comp2;

} parPol;

#endif /* DEFINICIONES_H_ */
