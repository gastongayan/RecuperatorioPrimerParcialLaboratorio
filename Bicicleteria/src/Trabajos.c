/*
 * Trabajos.c
 *      Author: GASTON ALEJANDRO GAYAN
 *               UTN FRA
 *               1RO "F"
*       RECUPERATORIO 1ER PARCIAL
 *
 */


#include "nexo.h"
#define TRAB 5
#define SER 4
#define VACIO 1
#define OCUPADO 0
int idAutonumerico = 0;
/**
 * @fn int MenuTrabajoABM(void)
 * @brief PRESENTACION DEL MENU DEL ABM QUE INTERACTUA CON EL USUARIO
 *
 * @return opcion elegida EXITO  (-1 ERROR)
 */
int MenuTrabajoABM(void){
	int opcion;
	printf("1. ALTA TRABAJO\n");
	printf("2. MODIFICAR TRABAJO\n");
	printf("3. BAJA TRABAJO\n");
	printf("4. LISTAR TRABAJO\n");
	printf("5. LISTAR SERVICIOS\n");
	printf("6. TOTAL\n");
	printf("7. LISTADO ORDENADO POR MARCA DE LA BICICLETA\n");
	printf("8. SERVICIO CON MAS TRABAJOS REALIZADOS\n");
	printf("9. CANTIDAD DE BICICLETAS DE COLOR ROJO QUE REALIZARON UN SERVICIO\n");
	printf("10.LISTADO DISCRIMINADO POR CLIENTE\n");
	printf("11.SUBTOTALES POR CLIENTES\n");
	printf("0. SALIR\n\n");
	if(!CargarUnEntero("Ingrese una opcion",&opcion, 0, 11))
	{
		printf("Error, datos ingresados incorrectos");
	}
	return opcion;

}



/**
 * @fn int InicializarTrabajos(eTrabajos[], int)
 * @brief  Inicializa el vector de trabajos, colocando en el campo isEmpty el valor 1 (VACIO)
 *
 * @param trabajos
 * @param tam
 * @return
 */
int InicializarTrabajos(eTrabajos trabajos[], int tam){
	int rtn=0;
	int i;
	if(trabajos!=NULL && tam>0)
	{
		for(i=0; i<tam; i++){
			trabajos[i].isEmpty=VACIO;

		}
		rtn=1;
	}
	return rtn;
}

/**
 * @fn int arrayTrabajosVacio(eTrabajos[],)
 * @brief Busca si el array se encuentra vacio
 *
 * @param trabajo
 * @param tam
 * @return 1 array vacio, 0 array con al menos un elemento
 */
int arrayTrabajosVacio(eTrabajos trabajo[], int tam){
	int rtn=1;
	for(int i=0; i<tam; i++)
	{
		if(trabajo[i].isEmpty==OCUPADO)
		{
			rtn=0;
		}
	}
	return rtn;
}

/**
 * @fn int control_TrabajosABM(int, eTrabajos[], int, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief  CONTROL DEL MENU DE OPERACIONES
 *
 * @param index
 * @param trabajo
 * @param tamTrabajo
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return
 */
int control_TrabajosABM(int index, eTrabajos trabajo[], int tamTrabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){


	switch(index){
		case 1:
			switch(AltaTrabajos(trabajo, tamTrabajo, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente))
			{
			case 1: //ALTA
				printf("Alta realizada con exito\n");
				break;

			case -1:
				printf("Lista de trabajos llena\n");
				break;

			case 0:
				printf("Error en carga de datos\n");
				break;

			}
			system("pause");
		break;


		case 2: // MODIFICACION
			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(Modificacion(trabajo, tamTrabajo, servicio, tamServicio,  bicicleta, tamBicicleta, cliente, tamCliente))
				{
					printf("Modificacion realizada!\n");
				}
			}
			else
			{
				printf("Debe de cargar al menos un trabajo para poder eliminar\n");
			}

			system("pause");
			break;


		case 3: // BAJA
			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(BajaTrabajos(trabajo, tamTrabajo, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente)){

					printf("Baja realizada con exito\n");

				}else{

					printf("No se han realizado bajas!\n");

				}
			}else{
				printf("Debe de cargar al menos un trabajo para poder eliminar\n");
			}
			system("pause");
			break;

		case 4: //LISTAR ORDENADO
			printf("----LISTADO DE TRABAJOS-----\n\n");
			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				OrdenarTrabajos(trabajo, tamTrabajo, bicicleta, tamBicicleta, 1);

				if(!ListarTrabajos(trabajo, tamTrabajo, servicio, tamServicio,  bicicleta, tamBicicleta, cliente, tamCliente))
				{
					printf("Error al mostrar listado");
				}
			}
			system("pause");
			break;

		case 5: // LISTAR SERVICIOS

			if(!ListarServicios(servicio, tamServicio))
			{
				printf("Error al mostrar listado");
			}
			system("pause");
			break;

		case 6://TOTAL POR LOS TRABAJOS REALIZADOS

			if(!arrayTrabajosVacio(trabajo, tamTrabajo) && !TotalTrabajos(trabajo, tamTrabajo, servicio, tamServicio))
			{
				printf("Error al calcular precios\n");
			}

			system("pause");
			break;

		case 7:// Listado de todos los trabajos ordenados por marca de la bicicleta.
			printf("----LISTADO DE TRABAJOS ORDENADOS POR MARCA DE BICICLETA-----\n\n");
			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				OrdenarTrabajos(trabajo, tamTrabajo, bicicleta, tamBicicleta, 0);

				if(!ListarTrabajos(trabajo, tamTrabajo, servicio, tamServicio,  bicicleta, tamBicicleta, cliente, tamCliente))
				{
					printf("Error al mostrar listado");
				}
			}
			system("pause");

			break;

		case 8: //El o los servicios con más trabajos realizados.

			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(!trabajos_contarServicios(trabajo, tamTrabajo, servicio, tamServicio))
				{
					printf("Error al contar servicios\n");
				}
			}else{
				printf("Debe de cargar al menos un trabajo\n");
			}
			system("pause");
			break;

		case 9://La cantidad de biciletas de color Rojo que realizaron un servicio elegido por el usuario.

			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(!trabajos_contarBiciRoja(trabajo, tamTrabajo, servicio, tamServicio, bicicleta, tamBicicleta))
				{
					printf("Error al contar servicios\n");
				}
			}else{
				printf("Debe de cargar al menos un trabajo\n");
			}
			system("pause");
			break;

		case 10: //INFORME DEL TOTAL DE TRABAJOS REALIZADOS A CADA CLIENTE Y SUMA DE TOTALES

			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(!listadoPorCliente(trabajo, tamTrabajo, cliente, tamCliente, bicicleta, tamBicicleta, servicio, tamServicio))
				{
					printf("Error al listar trabajos filtrado por clientes\n");
				}
			}else{
				printf("Debe de cargar al menos un trabajo\n");
			}
			system("pause");

			break;

		case 11:

			if(!arrayTrabajosVacio(trabajo, tamTrabajo))
			{
				if(!totalTrabajosPorCliente(trabajo, tamTrabajo, cliente, tamCliente, bicicleta, tamBicicleta, servicio, tamServicio))
				{
					printf("Error al listar trabajos filtrado por clientes\n");
				}
			}else{
				printf("Debe de cargar al menos un trabajo\n");
			}
			system("pause");
			break;
	}


	return index;
}


/**
 * @fn int get_Id(void)
 * @brief ID AUTONUMERICO
 *
 * @return DEVUELVE UN ID INCREMENTADO POR CADA VEZ QUE LLAMA LA FUNCION
 */
int get_Id(void){

	return idAutonumerico += 1;
}

/**
 * @fn int AltaTrabajos(eTrabajos[], int, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief DA DE ALTA UN NUEVO TRABAJO
 *
 * @param trabajo
 * @param tamTrabajo
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return -1 ERROR 1 EXITO
 */
int AltaTrabajos(eTrabajos trabajo[], int tamTrabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){
	puts("\n---ALTA---\n");
	int rtn=-1;
	int idTrabajo;
	int idBicicleta;
	int idServicio;
	int dia;
	int mes;
	int anio;
	int index;
	int idCliente;
	index=BuscarLibreTrabajo(trabajo, tamTrabajo);
	if(index!=-1)
	{
		rtn=0;
		if(CargaDatosTrabajos(&idBicicleta, &idServicio, &idCliente, &dia, &mes, &anio, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente))
		{
			idTrabajo = get_Id();

			trabajo[index].idTrabajo = idTrabajo;
			trabajo[index].idCliente = idCliente;
			trabajo[index].idBicicleta = idBicicleta;
			trabajo[index].idServicio = idServicio;
			trabajo[index].fecha.dia = dia;
			trabajo[index].fecha.mes = mes;
			trabajo[index].fecha.anio = anio;
			trabajo[index].isEmpty = OCUPADO;

			rtn=1;
		}

	}

	return rtn;

}

/**
 * @fn int CargaDatosTrabajos(int*, int*, int*, int*, int*, int*, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief FUNCION QUE SOLICITA AL USUARIO LA CARGA DE DATOS DEL ARRAY TRABAJO
 *
 * @param idBicicleta
 * @param idServicio
 * @param idCliente
 * @param dia
 * @param mes
 * @param anio
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return
 */
int CargaDatosTrabajos(int* idBicicleta, int* idServicio, int* idCliente, int* dia, int* mes, int* anio, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){

	int rtn;
	rtn=0;
	int menor;
	int mayor;

	if(ListarServicios(servicio, tamServicio))
	{
		menor = servicio_menorId(servicio, tamServicio);
		mayor = servicio_mayorId(servicio, tamServicio);

		if(!CargarUnEntero("Ingrese una opcion",idServicio, menor, mayor))
		{
			printf("Error, datos ingresados incorrectos");
		}

		if(*idServicio!=-1)
		{
			ListarClientes(cliente, tamCliente);
				if(!CargarUnEntero("Ingrese una opcion",idCliente, 1, 5))
				{
					printf("Error, datos ingresados incorrectos");
				}

				if(ListarBicicletas(bicicleta, tamBicicleta))
				{
					if(!CargarUnEntero("Ingrese una opcion",idBicicleta,bicicleta_menorId(bicicleta, tamBicicleta),bicicleta_mayorId(bicicleta, tamBicicleta)))
					{
						printf("Error, datos ingresados incorrectos");
					}

					if(*idBicicleta!=-1)
					{
						if(CargarUnEntero("Ingrese dia",dia, 1, 31) &&
								CargarUnEntero("Ingrese mes",mes, 1, 12) &&
								CargarUnEntero("Ingrese año",anio, 2010, 2050))
						{
							rtn=1;
						}

					}

				}


		}

	}


	return rtn;
}

/**
 * @fn int Modificacion(eTrabajos[], int, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief MODIFICA UN TRABAJO, PUDIENDO SOLO MODIFICAR EL SERVICIO O LA BICICLETA
 *
 * @param trabajo
 * @param tam
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return 0 ERROR 1 EXITO
 */
int Modificacion(eTrabajos trabajo[], int tam, eServicios servicio[],int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){

	eTrabajos auxiliar;
	int bandera;
	int idBicicleta;
	int idServicio;
	int opcion;
	int index;
	int mensaje;
	bandera=0;
	mensaje=0;

	printf("---MODIFICACION---\n");

	ListarTrabajos(trabajo, tam, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente);

	index=BuscarTrabajo(trabajo, tam);

	if(index!=-1){

		auxiliar=trabajo[index];

		do{

			MostrarUnTrabajo(auxiliar, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente, 1);

			if(!CargarUnEntero("Ingrese el elemento a modificar: \n1 - Marca de la Bicicleta \n2 - Servicio \n0 - Salir",&opcion, 0, 2)){
				printf("Error, Datos ingresados incorrectos\n");
			}

			switch (opcion){

				case 1:

					if(ListarBicicletas(bicicleta, tamBicicleta)){

						if(CargarUnEntero("Ingrese id",&idBicicleta, bicicleta_menorId(bicicleta, tamBicicleta), bicicleta_mayorId(bicicleta, tamBicicleta)))
						{
							if(idBicicleta!=-1)
							{
								auxiliar.idBicicleta = idBicicleta;
								bandera=1;
							}
						}


					}


					break;

				case 2:
					if(ListarServicios(servicio, tamServicio))
					{
						if(!CargarUnEntero("Ingrese Id:", &idServicio, servicio_menorId(servicio, tamServicio), servicio_mayorId(servicio, tamServicio)))
						{
							printf("Error, datos ingresados invalidos");
						}
						if(idServicio!=-1)
						{
							auxiliar.idServicio = idServicio;
						}
						bandera=1;
					}

					break;

				case -1:
					printf("Demasiados intentos realizados\n");
					break;
			}
		}while(opcion > 0);

		if(bandera==1){
			if(CargarUnEntero("Desea guardar los cambios? (1 = SI 0 = NO)",&mensaje, 0, 1)){

				if(mensaje==1){
					trabajo[index]=auxiliar;
				}
			}else{
				printf("Error, datos ingresados incorrectos");
			}
		}
	}
	return mensaje;
}

/**
 * @fn int TotalTrabajos(eTrabajos[], int, eServicios[], int)
 * @brief SUMA TOTAL DE TODOS LOS TRABAJOS REALIZADOS
 *
 * @param trabajo
 * @param tamTrabajo
 * @param servicio
 * @param tamServicio
 * @return 0 ERROR 1 EXITO
 */
int TotalTrabajos(eTrabajos trabajo[], int tamTrabajo, eServicios servicio[],int tamServicio){
	int rtn=0;
	int i;
	int j;

	float acumulador;
	acumulador=0;
	if(trabajo!=NULL)
	{
		rtn=1;
		for(i=0; i<tamTrabajo; i++){

			for(j=0; j<tamServicio; j++){

				if(trabajo[i].isEmpty==OCUPADO && servicio[j].idServicio == trabajo[i].idServicio){

					acumulador+=servicio[j].precio;

				}

			}
		}
		printf("El total por los trabajos realizados es $: %.2f \n",acumulador);
	}


	return rtn;

}
/**
 * @fn int BuscarLibreTrabajo(eTrabajos[], int)
 * @brief BUSCA INDICE EN EL ARRAY QUE NO SE ENCUETRE OCUPADO
 *
 * @param trabajo
 * @param tam
 * @return INDICE (EXITO) -1 (ERROR)
 */
int BuscarLibreTrabajo(eTrabajos trabajo[], int tam){
	int i;
	int index;
	index=-1;
	if(trabajo!=NULL && tam>0)
	{
		for(i=0; i<tam; i++)
		{
			if(trabajo[i].isEmpty==VACIO)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

/**
 * @fn int BajaTrabajos(eTrabajos[], int, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief BAJA LOGICA DEL TRABAJO, DESVINCULANDOLO CAMBIANDO SU VARIABLE ISEMPTY POR VACIO
 *
 * @param trabajo
 * @param tam
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return 0 ERROR 1 EXITO
 */
int BajaTrabajos(eTrabajos trabajo[],int tam, eServicios servicio[], int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){
	int rtn = 0;
	printf("\nBAJA TRABAJO\n");
	int index;
	int mensaje=0;
	if(trabajo!=NULL)
	{
		ListarTrabajos(trabajo, tam, servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente);

		index = BuscarTrabajo(trabajo, tam);

		if(index!=-1){
			MostrarUnTrabajo(trabajo[index], servicio, tamServicio,bicicleta, tamBicicleta, cliente, tamCliente, 1);
			if(!CargarUnEntero("Desea eliminar el dato? (1 = SI  0 = NO)",&mensaje, 0, 1))
			{
				printf("Error, datos ingresados incorrectos\n");
			}
		}

		if(mensaje==1)
		{
			trabajo[index].isEmpty=VACIO;
			printf("Dato eliminado con exito! \n");
			mensaje=0;
			rtn=1;

		}
		else
		{
			printf("Baja cancelada! \n");
			rtn=0;
		}
	}


	return rtn;

}



/**
 * @fn void MostrarUnTrabajo(eTrabajos, eServicios[], int, eBicicletas[], int, eClientes[], int, int)
 * @brief MUESTRA UN SOLO TRABAJO RELACIONADO CON TODAS LAS ESTRUCTURAS
 *
 * @param trabajo
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @param condicion
 */
void MostrarUnTrabajo(eTrabajos trabajo, eServicios servicio[], int tamServicio, eBicicletas bicicleta[], int tamBicicleta, eClientes cliente[], int tamCliente, int condicion){
	int indexServicio;
	int indexBicicleta;
	int indexCliente;

	indexServicio = servicio_buscarPorId(servicio, tamServicio, trabajo.idServicio);
	indexCliente = cliente_buscarPorId(cliente, tamCliente, trabajo.idCliente);
	indexBicicleta = bicicleta_buscarPorId(bicicleta, tamBicicleta, trabajo.idBicicleta);

	if(servicio!=NULL && bicicleta!=NULL && indexServicio!=-1 && indexBicicleta!=-1){
		if(condicion==1)
		{
			printf("| %4d | %10s | %10s | %10s | %10s | %8s | %8d | %4d/%d/%d | %.2f |\n", trabajo.idTrabajo, servicio[indexServicio].descripcion, cliente[indexCliente].nombre, cliente[indexCliente].apellido, bicicleta[indexBicicleta].marca, bicicleta[indexBicicleta].color,bicicleta[indexBicicleta].rodado, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio, servicio[indexServicio].precio);
		}
		if(condicion==0)
		{
			printf("| %4d | %10s | %10s | %8s | %8d | %4d/%d/%d | %.2f |\n", trabajo.idTrabajo, servicio[indexServicio].descripcion, bicicleta[indexBicicleta].marca, bicicleta[indexBicicleta].color,bicicleta[indexBicicleta].rodado, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio, servicio[indexServicio].precio);
		}


	}
}


/**
 * @fn int BuscarTrabajo(eTrabajos[], int)
 * @brief BUSQUEDA DE TRABAJO REALIZADO MEDIANTE ID
 *
 * @param trabajo
 * @param tam
 * @return EN CASO DE ENCONTRARSE EL ID, SE DEVUELVE EL INDICE DEL TRABAJO, -1 ERROR
 */
int BuscarTrabajo(eTrabajos trabajo[], int tam){
	int i;
	int idAuxiliar;
	int menor;
	int mayor;

	if(trabajo!=NULL && tam>0)
	{
		menor = trabajo_menorId(trabajo, tam);
		mayor = trabajo_mayorId(trabajo, tam);
		if(!CargarUnEntero("Ingrese ID",&idAuxiliar,menor ,mayor))
		{
			printf("Error, Datos ingresados incorrectos.");
		}

		if(idAuxiliar!=-1)
		{
			for(i=0; i<tam; i++){

				if(trabajo[i].isEmpty==OCUPADO && trabajo[i].idTrabajo==idAuxiliar){

					return i;
					break;
				}
			}
		}
	}


	return -1;
}
/**
 * @fn int ListarTrabajos(eTrabajos[], int, eServicios[], int, eBicicletas[], int, eClientes[], int)
 * @brief LISTA TOTALIDAD DE TRABAJOS RELACIONADOS CON TODAS LAS ESTRUCTURAS
 *
 * @param trabajo
 * @param tam
 * @param servicio
 * @param tamServicio
 * @param bicicleta
 * @param tamBicicleta
 * @param cliente
 * @param tamCliente
 * @return
 */
int ListarTrabajos(eTrabajos trabajo[], int tam, eServicios servicio[],int tamServicio, eBicicletas bicicleta[],int tamBicicleta, eClientes cliente[], int tamCliente){
	int i;
	int rtn=0;
	if(trabajo!=NULL && tam>0)
	{
		printf("| %4s | %10s | %10s | %10s | %10s | %8s | %8s | %11s | %4s |\n","ID","SERVICIO","NOMBRE","APELLIDO","MARCA","COLOR","RODADO","FECHA","PRECIO");
	}

	for(i=0; i<tam; i++){

		if(trabajo[i].isEmpty==OCUPADO)
		{

			MostrarUnTrabajo(trabajo[i], servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente, 1);
			rtn=1;
		}

	}
	return rtn;
}


/**
 * @fn int OrdenarTrabajos(eTrabajos[], int, eBicicletas[], int, int)
 * @brief
 * EN CASO DE CONDICION 1 ORDENA LOS TRABAJOS PRIMERO POR AÑO, EN CASO DE IGUALDAD, POR MARCA DE BICICLETA
 * EN CASO DE CONDICION 0 ORDENA SOLO POR MARCA DE BICICLETA
 * @param trabajo
 * @param tamTrabajo
 * @param bicicleta
 * @param tamBicicleta
 * @param condicion
 * @return
 */
int OrdenarTrabajos(eTrabajos trabajo[],int tamTrabajo, eBicicletas bicicleta[], int tamBicicleta, int condicion){
	eTrabajos auxiliar;
	int indexBicicleta1;
	int indexBicicleta2;
	int i;
	int j;
	char marca1[20];
	char marca2[20];

	int rtn=0;
	for(i=0;i<tamTrabajo-1; i++)
	{
		for(j=i+1; j<=tamTrabajo; j++){
			if(trabajo[i].isEmpty==OCUPADO && trabajo[j].isEmpty==OCUPADO)
			{
				if(trabajo[i].fecha.anio > trabajo[j].fecha.anio && condicion==1)
				{
					auxiliar = trabajo[i];
					trabajo[i] = trabajo[j];
					trabajo[j] = auxiliar;
					rtn=1;
				}
				else
				{
					if(trabajo[i].fecha.anio == trabajo[j].fecha.anio || condicion == 0)
					{
						indexBicicleta1=bicicleta_buscarPorId(bicicleta, tamBicicleta, trabajo[i].idBicicleta);
						indexBicicleta2=bicicleta_buscarPorId(bicicleta, tamBicicleta, trabajo[j].idBicicleta);
						strcpy(marca1, bicicleta[indexBicicleta1].marca);
						strcpy(marca2, bicicleta[indexBicicleta2].marca);
						if(strcmp(marca1, marca2)>0)
						{
							auxiliar = trabajo[i];
							trabajo[i] = trabajo[j];
							trabajo[j] = auxiliar;
							rtn=1;
						}
					}
				}
			}

		}
	}

	return rtn;

}
/**
 * @fn int trabajo_menorId(eTrabajos[], int)
 * @brief BUSCA EL ID MENOR DEL ARRAY DE TRABAJOS
 *
 * @param trabajo
 * @param tam
 * @return VALOR DEL ID MENOR
 */
int trabajo_menorId(eTrabajos trabajo[], int tam){

	int menor=0;

	if(tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(trabajo[i].isEmpty==OCUPADO && (menor==0 || trabajo[i].idTrabajo < menor))
			{
				menor=trabajo[i].idTrabajo;
			}
		}
	}

	return menor;
}

/**
 * @fn int trabajo_mayorId(eTrabajos[], int)
 * @brief BUSCA EL ID MAYOR DEL ARRAY DE TRABAJOS
 *
 * @param trabajo
 * @param tam
 * @return VALOR DEL ID MAYOR
 */

int trabajo_mayorId(eTrabajos trabajo[], int tam){

	int mayor=0;

	if(tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(trabajo[i].isEmpty==OCUPADO && (mayor==0 || trabajo[i].idTrabajo > mayor))
			{
				mayor=trabajo[i].idTrabajo;
			}
		}
	}

	return mayor;
}

/**
 * @fn int trabajos_contarServicios(eTrabajos[], int, eServicios[], int)
 * @brief CUENTA LA CANTIDAD DE SERVICIOS A FIN DE BRINDAR AL USUARIO EL SERVICIO CON MAS TRABAJOS REALIZADOS
 *
 * @param trabajo
 * @param tam
 * @param servicio
 * @param tamServicio
 * @return 0 ERROR 1 EXITO
 */
int trabajos_contarServicios(eTrabajos trabajo[], int tam, eServicios servicio[], int tamServicio)
{
	int rtn;
	int limpieza = 0;
	int parche = 0;
	int centrado = 0;
	int cadena = 0;
	int index;
	rtn=0;
	int idServicio = 0;
	if(trabajo!=NULL)
	{
		for(int i=0; i<tam; i++)
		{
			idServicio = trabajo[i].idServicio;
			switch (idServicio)
			{
			case 2000:
				limpieza++;
				break;

			case 2001:
				parche++;
				break;

			case 2002:
				centrado++;
				break;

			case 2003:
				cadena++;
				break;
			}

		}
		if(limpieza > parche && limpieza > centrado && limpieza > cadena)
		{
			index = servicio_buscarPorId(servicio, tamServicio, 2000);
			rtn=1;

		}
		if(parche > limpieza && parche > centrado && parche > cadena)
		{
			index = servicio_buscarPorId(servicio, tamServicio, 2001);
			rtn=1;

		}
		if(centrado > limpieza && centrado > parche && centrado > cadena)
		{
			index = servicio_buscarPorId(servicio, tamServicio, 2002);
			rtn=1;

		}
		if(centrado > limpieza && centrado > parche && centrado > cadena)
		{
			index = servicio_buscarPorId(servicio, tamServicio, 2003);
			rtn=1;

		}
		printf("El servicio con mas trabajos es: %s \n",servicio[index].descripcion);

	}

	return rtn;
}
 /**
   * @fn int trabajos_contarBiciRoja(eTrabajos[], int, eServicios[], int, eBicicletas[], int)
  * @brief CUENTA CANTIDAD DE TRABAJOS REALIZADOS A BICICLETAS DE COLOR ROJO, FILTRANDO POR EL ID DEL SERVICIO QUE INGRESA EL USUARIO
  *
  * @param trabajo
  * @param tam
  * @param servicio
  * @param tamServicio
  * @param bicicleta
  * @param tamBicicleta
  * @return 0 ERROR 1 EXITO
  */
int trabajos_contarBiciRoja(eTrabajos trabajo[], int tam, eServicios servicio[], int tamServicio, eBicicletas bicicleta[], int tamBicicleta){
	int rtn=0;
	int cantRojo=0;
	int idRojo;
	int idServicio;
	int index;
	int i;
	if(trabajo!=NULL && tam>0)
	{
		rtn=1;
		for(i=0; i<tamBicicleta; i++)
		{
			if(strcmp(bicicleta[i].color,"ROJO")==0)
			{
				idRojo = bicicleta[i].idBicicleta;
			}
		}

		ListarServicios(servicio, tamServicio);

		if(!CargarUnEntero("Ingrese id del servicio",&idServicio, servicio_menorId(servicio, tamServicio),servicio_mayorId(servicio, tamServicio)))
		{
			printf("Error, datos ingresados incorrectos\n");
		}

		if(idServicio!=-1)
		{
			index = servicio_buscarPorId(servicio, tamServicio, idServicio);
			for(i=0; i<tam; i++)
			{
				if(trabajo[i].idBicicleta==idRojo && trabajo[i].idServicio==idServicio)
				{
					cantRojo++;
				}
			}

			printf("Se han realizado %d de servicios de %s a bicicletas de color rojo.\n",cantRojo, servicio[index].descripcion);
		}
	}
	return rtn;

}
/**
 * @fn int listadoPorCliente(eTrabajos[], int, eClientes[], int, eBicicletas[], int, eServicios[], int)
 * @brief LISTADO DISCRIMINADO POR CLIENTE, EL USUARIO INGRESA EL ID DEL CLIENTE A BUSCAR Y SE DETALLAN LOS TRABAJOS REALIZADOS AL MISMO
 *
 * @param trabajo
 * @param tamTrabajo
 * @param cliente
 * @param tamCliente
 * @param bicicleta
 * @param tamBicicleta
 * @param servicio
 * @param tamServicio
 * @return 0 ERROR 1 EXITO
 */
int listadoPorCliente(eTrabajos trabajo[], int tamTrabajo, eClientes cliente[], int tamCliente, eBicicletas bicicleta[], int tamBicicleta, eServicios servicio[], int tamServicio){

	int idCliente;
	int index;
	int rtn=0;

	if(trabajo!=NULL && tamTrabajo > 0)
	{
		ListarClientes(cliente, tamCliente);
		do{
			CargarUnEntero("Ingrese id del cliente a buscar (0-Cancelar)",&idCliente, 0, 5);
			if(idCliente>0)
			{
				index=cliente_buscarPorId(cliente, tamCliente, idCliente);
				if(index!=-1)
				{
					printf("-------------------------------------------------\n\n");
					printf("Informe cliente: %s %s\n",cliente[index].nombre, cliente[index].apellido);
					printf("-------------------------------------------------\n\n");
				}
				printf("| %4s | %10s | %10s | %8s | %8s | %11s | %4s |\n","ID","SERVICIO","MARCA","COLOR","RODADO","FECHA","PRECIO");
				for(int i=0; i<tamTrabajo; i++)
				{
					if(trabajo[i].idCliente == idCliente)
					{
						MostrarUnTrabajo(trabajo[i], servicio, tamServicio, bicicleta, tamBicicleta, cliente, tamCliente, 0);

					}
				}

				rtn=1;

			}
		}while(idCliente>0);



	}
	return rtn;
}
 /**
   * @fn int totalTrabajosPorCliente(eTrabajos[], int, eClientes[], int, eBicicletas[], int, eServicios[], int)
  * @brief BUSCA TRABAJOS REALIZADOS A CADA CLIENTE Y EN CASO DE QUE EXISTA,
  *        ACUMULA LOS PRECIOS DE LOS SERVICIOS BRINDADOS EN LOS DIFERENTES TRABAJOS
  *
  * @param trabajo
  * @param tamTrabajo
  * @param cliente
  * @param tamCliente
  * @param bicicleta
  * @param tamBicicleta
  * @param servicio
  * @param tamServicio
  * @return 0 ERROR 1 EXITO
  */

int totalTrabajosPorCliente(eTrabajos trabajo[], int tamTrabajo, eClientes cliente[], int tamCliente, eBicicletas bicicleta[], int tamBicicleta, eServicios servicio[], int tamServicio)
{
	int rtn=0;
	int i;
	int j;
	int k;
	int idAux;
	float acumulador;
	if(trabajo!=NULL)
	{

		for(i=0; i<tamCliente; i++)
		{
			acumulador=0;
			idAux = cliente[i].id;

			for(j=0; j<tamTrabajo; j++)
			{

				if(trabajo[j].idCliente==idAux && trabajo[j].isEmpty==OCUPADO)
				{

					for(k=0; k<tamServicio; k++)
					{

						if(trabajo[j].idServicio == servicio[k].idServicio)
						{
							acumulador+=servicio[k].precio;
						}
					}
				}
			}

			if(acumulador!=0)
			{
				printf("El costo total de los trabajos realizados al cliente %s %s es: $ %.2f\n\n", cliente[i].nombre, cliente[i].apellido, acumulador);

			}
			rtn=1;
		}
	}
return rtn;

}
