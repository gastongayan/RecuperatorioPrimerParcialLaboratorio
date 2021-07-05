/*
 * Bicicleta.h
 *
 *  Created on: 11 may. 2021
 *      Author: Gaston A. Gayan
 */

#ifndef BICICLETAS_H_
#define BICICLETAS_H_

typedef struct{

	int idBicicleta;
	char marca[25];
	int rodado;
	char color[25];
	int isEmpty;

}eBicicletas;

int BuscarBicicleta(eBicicletas[], int);
void MostrarBicicleta(eBicicletas);
int ListarBicicletas(eBicicletas[], int);

int bicicleta_mayorId(eBicicletas bicicleta[], int tamBicicleta);
int bicicleta_menorId(eBicicletas bicicleta[], int tamBicicleta);

int bicicleta_buscarPorId(eBicicletas bicicleta[], int tamBicicleta, int id);

#endif /* BICICLETAS_H_ */
