/*
 * transferencia.c
 *
 *  Created on: 10/06/2013
 *      Author: utnso
 */

#include "transferencia.h"
#include "operaciones_bin.h"
#include "impresion.h"
#include <stdio.h>

func_trans ingreso_func_transferencia () {

	func_trans f;

	int i=0;
	int ing,ing2=0;

	printf ("Ingrese los ceros de la función (diez como max): \n"
			"(ngresar primero la parte real y luego la imaginaria)\n\n");

	for (i=0; i<10; i++){

		printf ("Cero [%d]: \n",i);
		scanf ("%d %d", &ing, &ing2);
		f.ceros[i].real= ing;
		f.ceros[i].imaginario= ing2;

	}

	printf("Ingrese los polos de la función (diez como max): \n");

	for (i=0; i<10; i++){

		printf ("Polo [%d]: \n",i);
		scanf ("%d %d", &ing, &ing2);
		f.polos[i].real= ing;
		f.polos[i].imaginario= ing2;

		}

	int k=0;

	printf ("Ingrese constante de proporcionalidad (k): ");
	scanf ("%d", &k);

	return f;

}

void evaluar (func_trans func) {

	complejoBin comp;

	printf ("Ingrese punto a evaluar: ");
	scanf ("%lf %lf", &comp.real, &comp.imaginario);

	int i;
	complejoBin vec_numerador [10];
	complejoBin vec_denominador [10];

	complejoBin numerador = {1,1};
	complejoBin denominador = {1,1};

	for (i=0; i<func.len_ceros; i++) {

		vec_numerador[i]= restar_bin (comp, func.ceros[i]);

	}

	for (i=0; i<func.len_polos; i++) {

		vec_denominador[i]= restar_bin (comp, func.polos[0]);
	}

	for (i=0; i<func.len_ceros; i++) {

		numerador = multiplicar_bin (numerador, vec_numerador [i]);

	}

	numerador.real = func.k*numerador.real;
	numerador.imaginario = func.k*numerador.imaginario;

	for (i=0; i<func.len_polos; i++) {

		denominador = multiplicar_bin (denominador, vec_denominador [i]);
	}

	complejoBin resultado_cociente = dividir_bin (numerador, denominador);

	printf ("F (%lf ; %lf) = ", comp.real, comp.imaginario);
	imprimir (&resultado_cociente, 0);

}

