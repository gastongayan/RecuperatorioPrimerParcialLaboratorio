/*
 * Clientes.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 */


#include "nexo.h"
#define VACIO 0
#define OCUPADO 1


/**
 * @fn void MostrarCliente(eClientes)
 * @brief MUESTRA UN CLIENTE
 *
 * @param cliente
 */
void MostrarCliente(eClientes cliente){

	printf("| %4d | %10s | %10s |\n", cliente.id, cliente.nombre, cliente.apellido);

}

/**
 * @fn int ListarClientes(eClientes[], int)
 * @brief LISTADO DE LA TOTALIDAD DE CLIENTES
 *
 * @param cliente
 * @param tam
 * @return 0 ERROR 1 EXITO
 */
int ListarClientes(eClientes cliente[], int tam)
{
	int i;
	int rtn=0;

	for(i=0; i<tam; i++){

		MostrarCliente(cliente[i]);
		rtn=1;
	}

	return rtn;
}

/**
 * @fn int cliente_buscarPorId(eClientes[], int, int)
 * @brief BUSCA CLIENTE POR ID
 *
 * @param cliente
 * @param tam
 * @param id
 * @return INDICE DEL CLIENTE BUSCADO POR ID O -1 ERROR
 */
int cliente_buscarPorId(eClientes cliente[], int tam, int id)
{
	int rtn=-1;
	if(cliente!=NULL && tam>0)
	{
		for(int i=0; i < tam; i++)
		{
			if(cliente[i].id == id)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

