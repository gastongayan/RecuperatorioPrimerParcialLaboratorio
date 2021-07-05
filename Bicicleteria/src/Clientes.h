/*
 * Clientes.h
 *
 *  Created on: 5 jul. 2021
 *      Author: gasto
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{
	int id;
	char nombre[51];
	char apellido[51];
	int isEmpty;
}eClientes;

#endif /* CLIENTES_H_ */
int ListarClientes(eClientes cliente[], int tam);
int cliente_buscarPorId(eClientes cliente[], int tam, int id);
void MostrarCliente(eClientes cliente);
