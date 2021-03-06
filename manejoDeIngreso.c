/*
 * manejoDeIngreso.c
 *
 *  Created on: 22/04/2013
 *      Author: utnso
 */

#include "manejoDeIngreso.h"
#include "transferencia.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "impresion.h"
#include "fasores.h"


void menu (){

	printf ("\nSeleccione operacion a efectuar:\n");

	printf ("Suma (+)\n"
			"Resta (-)\n"
			"Division (/)\n"
			"Multiplicacion (*)\n"
			"Potencia Natural (P)\n"
			"Radicacion Natural (R)\n"
			"Funcion Transferencia (T)\n");

	printf ("Ingrese 'Q' para salir\n\n");
}

void seleccion(char op) {

	char continuar='C';
	func_trans func;

	switch (op) {

	case 'Q':
		exit (-1);

	case 'F':
		operacion_suma_fasores ();
		proceder ();
		break;

	case 'P':
		if (seleccionarForma() == 'B') {
			int pot;
			complejoBin p = ingresarBinomico();
			printf ("Ingrese potencia natural: ");
			scanf ("%d", &pot);
			while (getchar() != '\n');
			complejoBin resPot = potenciaNat_bin (p, pot);
			printf ("\nResultado de la potencia: ");
			imprimir((void*)&resPot, 0);
			proceder ();
			break;
		}
		else {
			int pot;
			complejoPol p = ingresarPolar();
			printf ("Ingrese potencia natural: ");
			scanf ("%d", &pot);
			while (getchar() != '\n');
			complejoPol resPot = potenciaNat_pol (p, pot);
			printf ("\nResultado de la potencia: ");
			imprimir((void*)&resPot, 1);
			proceder ();
			break;
		}
		proceder ();
		break;

	case 'R':
		if (seleccionarForma() == 'B') {
			int raiz;
			complejoBin p = ingresarBinomico();
			printf("Ingrese raiz natural: ");
			scanf("%d", &raiz);
			while (getchar() != '\n')
				;
			raizN_esima_bin(p, raiz);
			proceder ();
			break;
		}
		else {
			int raiz;
			complejoPol p = ingresarPolar();
			printf("Ingrese raiz natural: ");
			scanf("%d", &raiz);
			while (getchar() != '\n')
				;
			raizN_esima_pol(p, raiz);
			proceder ();
			break;
		}
		proceder ();
		break;

	case '+':
		if (seleccionarForma ()=='B') {
			parBin par= cargar_parBinom ();
			complejoBin suma = sumar_bin (par.comp1, par.comp2);
			printf ("\nResultado de la suma: ");
			imprimir ((void*)&suma,0);
			proceder ();
			break;
		}
		else {
			parPol par= cargar_parPolar ();
			complejoPol suma = sumar_pol (par.comp1, par.comp2);
			printf ("\nResultado de la suma: ");
			imprimir ((void*)&suma,1);
			proceder ();
			break;
		}
		proceder ();
		break;

	case '-':
		if (seleccionarForma ()=='B') {
			parBin par= cargar_parBinom ();
			complejoBin resta = restar_bin (par.comp1, par.comp2);
			printf ("\nResultado de la resta: ");
			imprimir ((void*)&resta,0);
			proceder ();
			break;
		}
		else {
			parPol par= cargar_parPolar ();
			complejoPol resta = restar_pol (par.comp1, par.comp2);
			printf ("\nResultado de la resta: ");
			imprimir ((void*)&resta,1);
			proceder ();
			break;
		}
		proceder ();
		break;

	case '*':
		if (seleccionarForma ()=='B') {
			parBin par= cargar_parBinom ();
			complejoBin prod = multiplicar_bin (par.comp1, par.comp2);
			printf ("\nResultado del producto: ");
			imprimir ((void*)&prod,0);
			proceder ();
			break;
		}
		else {
			parPol par= cargar_parPolar ();
			complejoPol prod = multiplicar_pol (par.comp1, par.comp2);
			printf ("\nResultado del producto: ");
			imprimir ((void*)&prod,1);
			proceder ();
			break;
		}
		proceder ();
		break;

	case '/':
		if (seleccionarForma ()=='B') {
			parBin par= cargar_parBinom ();
			complejoBin div = dividir_bin (par.comp1, par.comp2);
			printf ("\nResultado del cociente: ");
			imprimir ((void*)&div,0);
			proceder ();
			break;
		}
		else {
			parPol par= cargar_parPolar ();
			complejoPol div = dividir_pol (par.comp1, par.comp2);
			printf ("\nResultado del cociente: ");
			imprimir ((void*)&div,1);
			proceder ();
			break;
		}
		proceder ();
		break;

	case 'T':

		func = ingreso_func_transferencia ();

		while (continuar=='C') {

			evaluar (func);

			printf ("\nEscriba 'C' para evaluar la funcion en otro punto"
					"\nEscriba 'V' para volver al menu\n\n");

			scanf ("%c", &continuar);
			while(getchar()!='\n');
		}

		proceder ();
		break;
	default:
		error ();
		break;

	}

}

char seleccionarForma () {

	char forma = 0;

	printf("Escriba B para ingresar los numeros en forma binomica,\n"
			"Escriba P para ingresar los numeros en forma polar\n\n");

	scanf("%c", &forma);

	while (getchar() != '\n')
		;

	if ((forma=='B') || (forma=='P')){


	} else error ();

	return forma;
}

parBin cargar_parBinom () {

	parBin par;

	 par.comp1 = ingresarBinomico();
	 par.comp2 = ingresarBinomico();

	 return par;
}

parPol cargar_parPolar () {

	parPol par;

	 par.comp1 = ingresarPolar();
	 par.comp2 = ingresarPolar();

	 return par;
}


complejoBin ingresarBinomico () {

	complejoBin bin;

	printf ("\nIngrese parte real: ");
	scanf ("%lf", &bin.real);
	while(getchar()!='\n');

	printf ("Ingrese parte imaginaria: ");
	scanf ("%lf", &bin.imaginario);
	while(getchar()!='\n');

	printf ("\nEl número ingresado es: ");
	imprimir (&bin, 0);

	return bin;
}

complejoPol ingresarPolar () {

	complejoPol pol;

	printf ("\nIngrese modulo: ");
	scanf ("%lf", &pol.modulo);
	while(getchar()!='\n');

	printf ("Ingrese argumento: ");
	scanf ("%lf", &pol.argumento);
	while(getchar()!='\n');

	printf ("\nEl número ingresado es: ");
	imprimir (&pol, 1);

	return pol;
}

void proceder () {

	printf ("\nPresione ENTER para continuar\n\n");
	getchar ();

}
