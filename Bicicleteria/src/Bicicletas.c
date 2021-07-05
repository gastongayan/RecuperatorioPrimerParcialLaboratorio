/*
 * Bicicleta.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 */

#include "nexo.h"
#define VACIO 0
#define OCUPADO 1


/**
 * @fn int BuscarBicicleta(eBicicletas[], int)
 * @brief BUSCA INDICE DE BICICLETA BUSCADA POR ID
 *
 * @param bicicleta
 * @param tam
 * @return INDICE EXITO  O -1 ERROR
 */

int BuscarBicicleta(eBicicletas bicicleta[], int tam){
	int i;
	int rtn=-1;
	int idAuxiliar;
	int menor;
	int mayor;

	menor = bicicleta_menorId(bicicleta, tam);
	mayor = bicicleta_mayorId(bicicleta, tam);
	 if(!CargarUnEntero("Ingrese ID", &idAuxiliar, menor,mayor ))
	 {

	 }

	for(i=0; i<tam; i++){
		if(bicicleta[i].idBicicleta==idAuxiliar){

			MostrarBicicleta(bicicleta[i]);
			system("pause");
			return i;
			break;
		}
	}

	return rtn;
}

/**
 * @fn void MostrarBicicleta(eBicicletas)
 * @brief MUESTRA UNA SOLA BICICLETA
 *
 * @param bicicleta
 */
void MostrarBicicleta(eBicicletas bicicleta){

	printf("| %4d | %10s | %7s | %7d |\n",bicicleta.idBicicleta, bicicleta.marca, bicicleta.color, bicicleta.rodado);

}

/**
 * @fn int ListarBicicletas(eBicicletas[], int)
 * @brief MUESTRA LA TOTALIDAD DE LAS BICICLETAS
 *
 * @param bicicleta
 * @param tam
 * @return
 */
int ListarBicicletas(eBicicletas bicicleta[], int tam)
{
	int i;
	int rtn=0;
	printf("| %4s | %10s | %7s | %7s |\n","ID","MARCA","RODADO","COLOR");
	for(i=0; i<tam; i++){

		MostrarBicicleta(bicicleta[i]);
		rtn=1;
	}
	return rtn;
}


/**
 * @fn int bicicleta_menorId(eBicicletas[], int)
 * @brief BUSCA ID MENOR DE LAS BICICLETAS
 *
 * @param bicicleta
 * @param tamBicicleta
 * @return ID MENOR o 0 ERROR
 */
int bicicleta_menorId(eBicicletas bicicleta[], int tamBicicleta){

	int menor=0;

	if(tamBicicleta > 0)
	{
		for(int i = 0; i < tamBicicleta; i++)
		{
			if(menor==0 || bicicleta[i].idBicicleta < menor)
			{
				menor=bicicleta[i].idBicicleta;
			}
		}
	}

	return menor;
}


/**
 * @fn int bicicleta_mayorId(eBicicletas[], int)
 * @brief BUSCA ID MAYOR DE LAS BICICLETAS
 *
 * @param bicicleta
 * @param tamBicicleta
 * @return ID MAYOR O 0 ERROR
 */
int bicicleta_mayorId(eBicicletas bicicleta[], int tamBicicleta){

	int mayor=0;

	if(tamBicicleta > 0)
	{
		for(int i = 0; i < tamBicicleta; i++)
		{
			if(mayor==0 || bicicleta[i].idBicicleta > mayor)
			{
				mayor=bicicleta[i].idBicicleta;
			}
		}
	}

	return mayor;
}
 /**
   * @fn int bicicleta_buscarPorId(eBicicletas[], int, int)
  * @brief BUSQUEDA POR ID DE LA BICICLETA
  *
  * @param bicicleta
  * @param tamBicicleta
  * @param id
  * @return INDICE O -1 ERROR
  */
int bicicleta_buscarPorId(eBicicletas bicicleta[], int tamBicicleta, int id)
{
	int rtn=-1;
	if(bicicleta!=NULL && tamBicicleta>0)
	{
		for(int i=0; i<tamBicicleta; i++)
		{
			if(bicicleta[i].idBicicleta == id)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
