/*
 * Servicios.h
 *
 *  Created on: 4 may. 2021
 *      Author: gasto
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct{
	int idServicio;  //empieza en 20000 con autoincremento
	char descripcion[50];
	float precio;
	int isEmpty;
}eServicios;


void MostrarServicio(eServicios servicio);
int ListarServicios(eServicios[], int);

int servicio_menorId(eServicios servicio[], int tamServicio);
int servicio_mayorId(eServicios servicio[], int tamServicio);


int servicio_buscarPorId(eServicios servicio[], int tamServicio, int id);
#endif /* SERVICIOS_H_ */
