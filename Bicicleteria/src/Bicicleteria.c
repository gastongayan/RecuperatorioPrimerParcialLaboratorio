/*
 ============================================================================
 Name        : Bicicleteria.c

 Author      :GASTON ALEJANDRO GAYAN
 *                 UTN FRA
 *                 1RO "F"
*         RECUPERATORIO 1ER PARCIAL

 Copyright   : 1 F
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define TRABAJOS 1000
#define SERVICIOS 4
#define BICICLETAS 5
#define CLIENTES 5

#define VACIO -1
#define OCUPADO 0


int main(void) {

	eTrabajos trabajo[TRABAJOS];

	eBicicletas bicicleta[BICICLETAS]={{25,"SHIMANO",20, "ROJO",OCUPADO},{26,"HARO",24, "AZUL",OCUPADO},{27,"AURORA",17, "GRIS",OCUPADO},{28,"VAIRO",14, "VIOLETA",OCUPADO},{29,"ROLLER",20, "CELESTE",OCUPADO}};

	eServicios servicio[SERVICIOS]={{2000,"LIMPIEZA",250, OCUPADO},{2001,"PARCHE", 300,OCUPADO},{2002,"CENTRADO",400,OCUPADO},{2003,"CADENA",350,OCUPADO}};

	eClientes cliente[CLIENTES]={{1,"Juan","Dominguez", OCUPADO},{2,"Pedro","Herrera", OCUPADO},{3,"Gaston","Gayan", OCUPADO},{4,"Fausto","Falcon", OCUPADO},{5,"Matias","Romero", OCUPADO}};
	int menuTrabajo;

	setbuf(stdout, NULL);
	InicializarTrabajos(trabajo, TRABAJOS);

	//ABM
	do{
		menuTrabajo=MenuTrabajoABM();
		control_TrabajosABM(menuTrabajo, trabajo, TRABAJOS, servicio, SERVICIOS, bicicleta, BICICLETAS, cliente, CLIENTES);

	}while(menuTrabajo!=0);



	return EXIT_SUCCESS;
}





