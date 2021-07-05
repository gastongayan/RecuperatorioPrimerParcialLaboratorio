/*
 * Servicios.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 */

#include "nexo.h"
#define VACIO -1
#define OCUPADO 0

/**
 * @fn int ListarServicios(eServicios[], int)
 * @brief LISTA LA TOTALIDAD DE LOS SERVICIOS
 *
 * @param servicios
 * @param tam
 * @return 1 encontro servicio 0 tamaño de array vacio
 */
int ListarServicios(eServicios servicios[], int tam){
	int i;
	int rtn=0;
	if(tam>0)
	{
		printf("| %4s | %10s | %5s |\n","ID","DESCRIPCION","COSTO");
		for(i=0;i<tam;i++){
			if(servicios[i].isEmpty==OCUPADO){
				MostrarServicio(servicios[i]);
				rtn=1;
			}

		}
	}

	return rtn;
}

/**
 * @fn int MostrarServicio(eServicios)
 * @brief MUESTRA UN SOLO SERVICIO
 *
 * @param servicio
 * @return 0 servicio NULL o 1 exito
 */
void MostrarServicio(eServicios servicio){

	printf("| %4d | %10s | %.2f |\n",servicio.idServicio, servicio.descripcion, servicio.precio);

}

/**
 * @fn int servicio_buscarPorId(eServicios[], int, int)
 * @brief Obtiene indice del servicio buscado por id
 *
 * @param servicio
 * @param tam
 * @param id
 * @return -1 Error, indice del servicio (OK)
 */
int servicio_buscarPorId(eServicios servicio[], int tamServicio, int id){
	int rtn=-1;
	if(servicio!=NULL && tamServicio>0)
	{
		for(int i=0; i<tamServicio; i++)
		{
			if(servicio[i].idServicio == id)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


/**
 * @fn int servicio_menorId(eServicios[], int)
 * @brief Busca el id menor de los servicios
 *
 * @param servicio
 * @param tamServicio
 * @return menor id o 0 error
 */
int servicio_menorId(eServicios servicio[], int tamServicio){
	int menor=0;

	if(tamServicio>0)
	{
		for(int i=0; i<tamServicio; i++)
		{
			if(menor==0 || servicio[i].idServicio < menor)
			{
				menor=servicio[i].idServicio;
			}
		}
	}

	return menor;
}


/**
 * @fn int servicio_mayorId(eServicios[], int)
 * @brief Busca el mayor id del vector de servicios
 *
 * @param servicio
 * @param tamServicio
 * @return id mas alto o 0 error
 *  */

int servicio_mayorId(eServicios servicio[], int tamServicio){
	int mayor=0;

	if(tamServicio>0)
	{
		for(int i=0; i<tamServicio; i++)
		{
			if(mayor==0 || servicio[i].idServicio > mayor)
			{
				mayor=servicio[i].idServicio;
			}
		}
	}

	return mayor;
}



