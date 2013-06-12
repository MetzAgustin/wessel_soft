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
#include <string.h>
#include <stdlib.h>

func_trans ingreso_func_transferencia () {

	func_trans f;

	printf ("Ingrese los ceros de la función (diez como max): \n\n");

	ingreso_ceros_polos (0,f.ceros,&f.len_ceros);


	printf("Ingrese los polos de la función (diez como max): \n\n");

	ingreso_ceros_polos (1,f.polos,&f.len_polos);

	printf ("Ingrese constante de proporcionalidad (k): ");
	scanf ("%d", &f.k);
	while(getchar()!='\n');
	
	printf ("\n\nF (s) = %d ", f.k);
	
	int i=0;
	for (i=0; i<=f.len_ceros;i++) {
		
		printf ("[ s - ( %d , %d ) ] ", f.ceros[i].real, f.ceros[i].imagin);
		
	};
	
	printf ("         ------------------------------------------");
	
	for (i=0; i<=f.len_polos;i++) {
		
		printf ("[ s - ( %d , %d ) ] ", f.polos[i].real, f.polos[i].imagin);
		
	};
	
	printf ("\n\n");

	return f;

}

void evaluar (func_trans func) {

	complejoBin comp;

	printf ("Ingrese punto a evaluar: ");
	scanf ("%lf %lf", &comp.real, &comp.imaginario);
	while(getchar()!='\n');

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
	imprimir ((void*)&resultado_cociente, 0);

}

void ingreso_ceros_polos (int t, complejoBin* array, int* total) {

	char fin = 'S';
	int i, ing, ing2;
	char *cad= malloc (5);

	if (t==0) {
		strcpy (cad, "Cero");
	} else {
		strcpy (cad, "Polo");
	}

	for (i = 0; (i < 10) & (fin == 'S'); i++) {

		printf("%s [%d]: \n",cad, i);
		scanf("%d %d", &ing, &ing2);
		while (getchar() != '\n')
			;

		if (i != 9) {

			printf("Desea ingresar otro %s? \nS-Si \nN-No\n", cad);
			scanf("%c", &fin);
			while (getchar() != '\n')
				;
		}

		array[i].real = ing;
		array[i].imaginario = ing2;

	}

	*total = i;

}
