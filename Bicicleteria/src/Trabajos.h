/*
 * Trabajos.h
 *
 *  Created on: 4 may. 2021
 *      Author: gasto
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_
typedef struct{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct{
	int idTrabajo;
	int idServicio;
	int idCliente;
	int idBicicleta;
	eFecha fecha;
	int isEmpty;

}eTrabajos;




int MenuTrabajoABM(void);

int InicializarTrabajos(eTrabajos trabajos[], int tam);
int arrayTrabajosVacio(eTrabajos trabajo[], int tam);

int BuscarTrabajo(eTrabajos[], int);
int BuscarLibreTrabajo(eTrabajos[], int);


int control_TrabajosABM(int index, eTrabajos trabajo[], int tamTrabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);

int AltaTrabajos(eTrabajos trabajo[], int tamTrabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);
int CargaDatosTrabajos(int* idBicicleta, int* idServicio, int* idCliente, int* dia, int* mes, int* anio, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);

int Modificacion(eTrabajos trabajo[], int tam, eServicios servicio[],int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);
int BajaTrabajos(eTrabajos trabajo[],int tam, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);

int ListarTrabajos(eTrabajos trabajo[], int tam, eServicios servicio[],int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente);
void MostrarUnTrabajo(eTrabajos trabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[], int tamBicicleta, eClientes cliente[], int tamCliente, int condicion);

int trabajo_menorId(eTrabajos trabajo[], int tam);
int trabajo_mayorId(eTrabajos trabajo[], int tam);

int OrdenarTrabajos(eTrabajos trabajo[],int tamTrabajo, eBicicletas bicicleta[], int tamBicicleta, int condicion);

int TotalTrabajos(eTrabajos[], int, eServicios[],int);

int trabajos_contarServicios(eTrabajos trabajo[], int tam, eServicios servicio[], int tamServicio);
int trabajos_contarBiciRoja(eTrabajos trabajo[], int tam, eServicios servicio[], int tamServicio, eBicicletas bicicleta[], int tamBicicleta);

int listadoPorCliente(eTrabajos trabajo[], int tamTrabajo, eClientes cliente[], int tamCliente, eBicicletas bicicleta[], int tamBicicleta, eServicios servicio[], int tamServicio);
int totalTrabajosPorCliente(eTrabajos trabajo[], int tamTrabajo, eClientes cliente[], int tamCliente, eBicicletas bicicleta[], int tamBicicleta, eServicios servicio[], int tamServicio);

#endif /* TRABAJOS_H_ */
