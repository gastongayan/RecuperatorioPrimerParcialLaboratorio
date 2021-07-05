/*
 * input.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 */



//Funcion que recibe el valor como parametro devolviendolo incrmentado en 1
#include "nexo.h"
#include "String.h"
#include "stdio.h"
#include "ctype.h"

int incrementarId(int id){
	id++;
	return id;
}
int validar_numero(char numero[51]){
	int len;
	int i;
	int rtn=0;
	len=strlen(numero);
	for(i=0; i<len; i++)
	{
		if(!isdigit(numero[i]))
		{
			rtn=1;
			break;
		}
	}
	return rtn;
}


int CargarUnEntero(char mensaje[51], int* entero, int menor, int mayor)
{


	char numeroChar[51];
	int rtn=0;
	int contador=0;
	int numeroInt;
	do{
		printf("%s: ",mensaje);
		fflush(stdin);
		scanf("%s",numeroChar);
		if(strcmp(numeroChar,"")!=0)
		{

			if(strlen(numeroChar)!=0)
			{
				if(!validar_numero(numeroChar))
				{
					numeroInt = atoi(numeroChar);
					if(!ValidarRango(&numeroInt, menor, mayor))
					{
						*entero=numeroInt;
						rtn=1;
					}else{
						contador++;
					}
				}
			}
		}
	}while(contador<3 && rtn==0);


	return rtn;
}



int BuscarIdMayor(eServicios servicio[], int tamServicio){
	int i;
	int mayor;
	mayor=0;
	for(i=0; i<tamServicio; i++){
		if(servicio[i].idServicio>mayor){
			mayor=servicio[i].idServicio;
		}
	}
	return mayor;
}
int BuscarIdMenor(eServicios servicio[], int tamServicio){
	int i;
	int menor;
	menor=0;
	for(i=0; i<tamServicio; i++){
		if(servicio[i].idServicio<menor || menor==0){
			menor=servicio[i].idServicio;
		}
	}
	return menor;
}
int ValidarRango(int* numero, int menor, int mayor){

	int rtn=0;

	if(*numero<menor || *numero>mayor){
		printf("Error, ingrese datos entre %d y %d\n",menor, mayor);
		rtn=1;

	}
	return rtn;
}

void CargarUnaCadena(char mensaje[], char datoIngresado[]){

	char auxString[500];

	do{
		printf("%s:", mensaje);
		fflush(stdin);
		scanf("%s",auxString);
	}while(strlen(auxString)>50 || strlen(auxString)==0);
	strcpy(datoIngresado, auxString);

}

