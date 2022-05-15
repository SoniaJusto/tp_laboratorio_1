/*
 ============================================================================
 Name        : Trabajo Practico Nº2
 Author      : JUSTO SONIA

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT 50
#define LIBRE 0
#define OCUPADO 1


#include "ArrayPassenger.h"
#include "Validaciones.h"

int main()
{
    setbuf(stdout, NULL);
    int cantidadDatos, opcion, retornoAlta, id,typePassenger, AscendenteODescendente , idStatusFlight ;
    float price;
    cantidadDatos=0;

    char name[6]= "sonia";
	char lastName[6]="justo";
	char flycode[6] ="AC150";
    id= 999;
	typePassenger=1;
	price= 1500;
	idStatusFlight= 1;

    ePassenger pasajeros [CANT];
    eTipoPasajero tipoPasajero [2] = { {1,"Turista"}, {2,"Premium"} };
	eEstadoVuelo estadoVuelo [2] = { {1,"Activo"}, {2,"Demorado"} };


     //INICIALIZACION
     initPassengers (pasajeros , CANT);
     addPassenger ( pasajeros , CANT, id, name, lastName, price, typePassenger,  flycode ,idStatusFlight ) ;

  do
    {
      printf ("----------------------------------------------------------------------------");
      opcion = MenuOpciones("\n<< MENU DE OPCIONES >>  \n\n1. Alta\n2. Modificar\n3. Baja \n4. Informar\n5. Cargado al Momento \n6. Salir \n\n  Introduzca una opcion (1-6): ");
      printf ("----------------------------------------------------------------------------");

      switch (opcion)
	{

	 //ALTA
	case 1:

    retornoAlta= Alta_EspacioLibre (pasajeros, CANT, tipoPasajero , estadoVuelo  );


    switch(retornoAlta)
	  {
		case -1:
		printf("\n NO hay espacio!!!! \n");
		break;
		default:
		printf("\n Ticket cargado con EXITO!!! \n ");
		cantidadDatos++;
		break;
		}
	break;

	  //MODIFICAR
	case 2:
	    if (cantidadDatos>0){
	    Modificar_DatosPasajero (pasajeros, CANT , tipoPasajero,estadoVuelo );
	  }else{
	      printf ("\n NO hay datos cargados al momento \n");
	      break;
	  }
	break;

	  //BAJA
      case 3:
      	if (cantidadDatos>0){
	        Baja_Pasajero (pasajeros, CANT );
	        cantidadDatos--;
	    }else{
	      printf ("\n NO hay datos cargados al momento \n");
	      break;
	  }
	  break;

	//INFORMAR
	case 4:
	if (cantidadDatos>0){
	  AscendenteODescendente= Ascendente_Descendente ( );
      sortPassengers( pasajeros, CANT, AscendenteODescendente, tipoPasajero);
      Total_Promedio_Pasajes (pasajeros, CANT );
      sortPassengersByCode (pasajeros, CANT ,estadoVuelo );

	 }else{
	    printf ("\n NO hay datos cargados al momento \n");
	   break;
	 }
	 break;


	//VISUALIZAR CARGADO AL MOMENTO
	case 5:
	if (cantidadDatos>0){
	     printf("\n  ID    |    NOMBRE   |   APELLIDO   |   PRECIO $   |   CODIGO DE VUELO  |  TIPO DE PASAJERO |  ESTADO DE VUELO  |  ");
	     printPassenger(pasajeros , CANT );
	  }else{
	      printf ("\n NO hay datos cargados al momento \n");
	      break;
	  }
	break;

	//SALIR
	case 6:
	printf ("\n\n PROGRAMA FINALIZADO ..... \n");
	break;
	}

    }while (opcion != 6);

    return 0;

}
