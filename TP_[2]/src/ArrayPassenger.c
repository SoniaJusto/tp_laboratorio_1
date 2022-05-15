#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "Validaciones.h"

#define CANT 50
#define LIBRE 0
#define OCUPADO 1

static int idIncremental = 1000;

static int ObtenerId();

static int ObtenerId() {
return idIncremental++;
}

/// \fn int initPassengers(ePassenger[], int)
/// \brief  Para indicar que todas las posiciones en la matriz están
///         vacías, esta función pone el indicador (isEmpty) en LIBRE en todas las posiciones de la matriz.
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \return

//INICIALIZACION
int initPassengers(ePassenger list[], int len){

    for (int i=0; i<len ; i++){
        list[i].isEmpty= LIBRE;
    }

    return 0;
}

/// \fn int addPassenger(ePassenger[], int, int, char[], char[], float, int, char[], int)
/// \brief add agregar en una lista existente de pasajeros los valores
///            recibidos como parámetros* en la primera posición vacía
/// \param list matriz de ePassenger
/// \param len int len Longitud de la matriz
/// \param id int
/// \param name[] char
/// \param lastName[] char
/// \param price float
/// \param typePassenger int
/// \param flycode[] char
/// \param idStatusFlight int
/// \return Devuelve (-1) si hay error  - (0) si está bien


//PRIMER PASAJERO CARGADO EN EL PRIMER ESPACIO VACIO
int addPassenger(ePassenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger,
                  char flycode[], int idStatusFlight){

  int carga=0;

  list[0].id= id;
  strcpy (list[0].name ,name );
  strcpy (list[0].lastName ,lastName );
  list[0].price= price;
  list[0].idTypePassenger= typePassenger;
  strcpy (list[0].flycode ,flycode );
  list[0].idStatusFlight= idStatusFlight;
  list[0].isEmpty= OCUPADO;

  return carga  ;

}

/// \fn int Buscar_EspacioLibre(ePassenger[], int)
/// \brief busca posicion libre en el array
/// \param list matriz de ePassenger
/// \param  int len Longitud de la matriz
/// \return posicion libre encontrada



//ALTA
int Buscar_EspacioLibre (ePassenger list[],  int len ){
   int espacioLibre;

    if (list !=NULL){
        if (len >= 0){
            for (int i=0; i<len; i++){
                if (list[i].isEmpty== LIBRE ){
                    espacioLibre= i;
                    break;
                }
            }
        }
    }
    return espacioLibre;
}


/// \fn int Alta_EspacioLibre(ePassenger[], int, eTipoPasajero[], eEstadoVuelo[])
/// \brief pide al usuario ingresar datos en la posicion libre encontrada
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param tipoPasajero matriz de eTipoPasajero
/// \param estadoVuelo matriz de eEstadoVuelo
/// \return (0) si OK, o (-1) ERROR
///
int Alta_EspacioLibre (ePassenger list[],  int len , eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo [] ){
    int retornoLibre;

	if (list != NULL) {
		if (len >= 0) {
			//BUSCAR ESPACIO LIBRE
			retornoLibre = Buscar_EspacioLibre(list, len);

			if (retornoLibre >= 0) {
				//CARGAR DATOS
				list[retornoLibre] = PedirDatos_Album (tipoPasajero,estadoVuelo );
				retornoLibre = 0;
			}
		}
	}
	return retornoLibre;
}

/// \fn ePassenger PedirDatos_Album(eTipoPasajero[], eEstadoVuelo[])
/// \brief pide al usuario que ingrese datos del pasajero
/// \param tipoPasajero matriz de eTipoPasajero
/// \param estadoVuelo matriz de eEstadoVuelo
/// \return datos del pasajero
///
ePassenger PedirDatos_Album (eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo []) {

    ePassenger pasajero;
    //nombre
    printf ("\n Ingrese el nombre:  ");
    fflush(stdin);
	scanf(" %[^\n]", pasajero.name );


	//apellido
	printf ("\n Ingrese el apellido:  ");
    fflush(stdin);
	scanf(" %[^\n]", pasajero.lastName );


    //precio
    pasajero.price= Validar_precio ();

    //codigo vuelo
    printf ("\n Ingrese el codigo de vuelo :  ");
    fflush(stdin);
	scanf(" %[^\n]", pasajero.flycode );


	//tipo de pasajero
	pasajero.idTypePassenger= ValidarTipoPasajero (tipoPasajero);

    //estado de vuelo
    pasajero.idStatusFlight= Validar_estadoVuelo (estadoVuelo);

	pasajero.isEmpty = OCUPADO;
	pasajero.id= ObtenerId();

	return pasajero;
 }

/// \fn void MostrarUnTicket(ePassenger)
/// \brief muestra datos cargados en el array
/// \param list

//MOSTRAR LISTADO
void  MostrarUnTicket(ePassenger list){

  printf("\n %4d    %10s   %10s   %15.2f   %15s  %20d  %16d  \n",list.id,
	                                                            list.name,
	                                                            list.lastName,
	                                                            list.price,
	                                                            list.flycode,
	                                                            list.idTypePassenger,
	                                                            list.idStatusFlight);
}

/// \fn void printPassenger(ePassenger[], int)
/// \brief
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz

void printPassenger (ePassenger list[] , int len ){

    for(int i=0; i<len; i++ ){
		        if(list[i].isEmpty == OCUPADO)
	        	{
	        		MostrarUnTicket(list[i] );
	        	}
        }

}

/// \fn int Ingreso_id(ePassenger[], int)
/// \brief pide al usuario que ingrese un id
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \return id ingresado previa validacion

// Busqueda pasajero
int Ingreso_id (ePassenger list[] , int len){
     int id;
     id = ValidarId_Amodificar ( list ,  len );
     return id;
}


/// \fn int findPassengerById(ePassenger[], int, int)
/// \brief
/// \pre
/// \post
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param int id recibido como parametro
/// \return (id) OK , o (99) ERROR
///
int findPassengerById(ePassenger list[], int len, int id){
    int id_Modificar;
    int i;

     for (i=0; i<len ; i++ ){
        if (list[i].id== id && list[i].isEmpty == OCUPADO ){
            printf ("\n Hemos encontrado un pasajero con ese N° de Id!! \n ");
            printf("\n  ID    |    NOMBRE   |   APELLIDO   |   PRECIO $   |   CODIGO DE VUELO  |  TIPO DE PASAJERO |  ESTADO DE VUELO  |  ");
            MostrarUnTicket(list[i]);
            id_Modificar=id;
            break;
        }else if(list[i].id!= id && list[i].isEmpty != OCUPADO ) {
            id_Modificar= 99;
            break;
        }
    }

    return id_Modificar;
}

/// \fn void Modificar_DatosPasajero(ePassenger[], int, eTipoPasajero[], eEstadoVuelo[])
/// \brief
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param tipoPasajero matriz de eTipoPasajero
/// \param estadoVuelo  matriz de eEstadoVuelo
 void Modificar_DatosPasajero (ePassenger list[] , int len , eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo [] ){

    int retornoIngreso_id, retorno_Busqueda,opcion_Menu , i ;

    retornoIngreso_id = Ingreso_id (list , len);
    retorno_Busqueda= findPassengerById( list , len, retornoIngreso_id );

    for (i=0; i<len ; i++ ){
        if (retorno_Busqueda == list[i].id && list[i].isEmpty ==OCUPADO ){
            do{
                opcion_Menu= Menu_Modificar();

                  switch( opcion_Menu ){
                   //nombre
			      case 1:
			      printf ("\n Ingrese el nombre:  ");
                  fflush(stdin);
	              scanf(" %[^\n]", list[i].name );
			      break;

                  //apellido
			      case 2:
			      printf ("\n Ingrese el apellido:  ");
                  fflush(stdin);
	              scanf(" %[^\n]", list[i].lastName );
		          break;

                  //precio
		     	  case 3:
		     	  list[i].price= Validar_precio ();
		     	  break;

                  //tipo de pasajero
                   case 4:
                  list[i].idTypePassenger= ValidarTipoPasajero (tipoPasajero);
		          break;

                  //codigo de vuelo
                  case 5:
                  printf ("\n Ingrese el codigo de vuelo :  ");
                  fflush(stdin);
	              scanf(" %[^\n]",  list[i].flycode );
		          break;

		     	  case 6:
		     	  break;

		     	  default:
		    	  printf( "\n La opci%cn ingresada es INCORRECTA...", 162 );
		    	  break;
                }

            }while (opcion_Menu != 6 );
        }
    }

 }

 /// \fn int Menu_Modificar()
 /// \brief solicita al usuario que dato desea modificar
 /// \return opcion seleccionada por usuario para modificar dato
 ///
 int Menu_Modificar (){
    int opcion;
    opcion= Valida_Menu();
    return opcion;
}

/// \fn void removePassenger(ePassenger[], int, int)
/// \brief  Eliminar un pasajero por Id (poner isEmpty Flag en 1)
 /// \param list matriz de ePassenger
 /// \param int len Longitud de la matriz
/// \param id dato recibido como parametro


//BAJA
void removePassenger (ePassenger list[], int len,int id){
    int i ;
    char confirmar;

   	for( i=0; i<len; i++ ){
	    if( list[i].id == id && list[i].isEmpty == OCUPADO ){
	   	    MostrarUnTicket(list[i]);
	   	    printf( "\n Dar de baja? [S|N]:" );
			scanf(" %c", &confirmar);
			confirmar = toupper( confirmar );
			if( confirmar == 'S' ){
				list[i].isEmpty = -1;
				printf( "\n Los datos han sido borrados... \n " );
			}
	    }
    }

}

/// \fn void Baja_Pasajero(ePassenger[], int)
/// \brief solicita numero de id al usuario, valida y pasa por parametro a la funcion removePassenger
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz

void Baja_Pasajero (ePassenger list[], int len ){
    int retornoIngreso_id;

    retornoIngreso_id = Ingreso_id (list , len);
    removePassenger ( list, len,retornoIngreso_id);
}

/// \fn int Ascendente_Descendente(void)
/// \brief solicita opcion de visualizacion- Ascendente / Descendente
/// \return opcion seleccionada, previa validacion

//LISTAR-ORDENAR
int Ascendente_Descendente (void ){
    int opcion;
    opcion= Validar_Ascendente_Descendente ( );
    return opcion;
}

/// \fn void Ascendente(ePassenger[], int, eTipoPasajero[])
/// \brief ordena los apellidos de los pasajeros de forma ascendente
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param tipoPasajero matriz de eTipoPasajero
///
void Ascendente (ePassenger list[], int len, eTipoPasajero tipoPasajero [] ){
    ePassenger aux;
    int i, j ;

  for( i=0; i<len-1 ;i++)
		for( j=i+1; j<len ;j++)
			if((strcmp(list[i].lastName ,list[j].lastName))>0){
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}

	for(  i=0; i<len; i++){
	    if(list[i].isEmpty == OCUPADO){
	       for(int j=0; j<4; j++)
	        if (list[i].idTypePassenger == tipoPasajero[j].idTypePassenger )
	        printf("\n %4d    %10s   %10s   %15.2f   %15s  %20s  %16d  \n",list[i].id,
	                                                                       list[i].name,
	                                                                       list[i].lastName,
	                                                                       list[i].price,
	                                                                       list[i].flycode,
	                                                                       tipoPasajero[j]. typePassenger,
	                                                                       list[i].idStatusFlight);

	    }

	    }
}

/// \fn void Descendente(ePassenger[], int, eTipoPasajero[])
/// \brief ordena los apellidos de los pasajeros de forma Descendente
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param tipoPasajero matriz de eTipoPasajero
///
void Descendente (ePassenger list[], int len, eTipoPasajero tipoPasajero [] ){
  ePassenger aux;
   int i, j ;

  for( i=0; i<len-1 ;i++)
		for( j=i+1; j<len ;j++)
			if((strcmp(list[i].lastName ,list[j].lastName))<0){
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;

			}

	for( i=0; i<len; i++){
	    if(list[i].isEmpty == OCUPADO){
	        for(int j=0; j<4; j++)
	        if (list[i].idTypePassenger == tipoPasajero[j].idTypePassenger )
	        printf("\n %4d    %10s   %10s   %15.2f   %15s  %20s  %16d  \n",list[i].id,
	                                                                       list[i].name,
	                                                                       list[i].lastName,
	                                                                       list[i].price,
	                                                                       list[i].flycode,
	                                                                       tipoPasajero[j]. typePassenger,
	                                                                       list[i].idStatusFlight);

	    }
    }


}

/// \fn void sortPassengers(ePassenger[], int, int, eTipoPasajero[])
/// \brief muestra deacuerdo a lo ingresado por usuario visualizacion apellidos ascendente o descendente
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param order retorno de opcion seleccionada por usuario para visualizacion ascendente o descendente
/// \param tipoPasajero matriz de eTipoPasajero
void sortPassengers(ePassenger list[], int len, int order, eTipoPasajero tipoPasajero [] ){

    switch (order ){
        case 1:
	    printf("\n  ID    |    NOMBRE   |   APELLIDO   |   PRECIO $   |   CODIGO DE VUELO  |  TIPO DE PASAJERO |  ESTADO DE VUELO  |  ");
        Ascendente ( list,  len, tipoPasajero );
        break;

        case 2:
	    printf("\n  ID    |    NOMBRE   |   APELLIDO   |   PRECIO $   |   CODIGO DE VUELO  |  TIPO DE PASAJERO |  ESTADO DE VUELO  |  ");
        Descendente ( list,  len, tipoPasajero );
        break;

        default:
        printf("\n Intente nuevamente! ...\n  ");
        break;
     }
}

/// \fn void Total_Promedio_Pasajes(ePassenger[], int)
/// \brief muestra el calculo del total y promedio del precio de los pasajes y cantidad de pasajeros que superan el promedio
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
//ORDENAR-total y promedio precios pasajes, cuantos superan promedio
void Total_Promedio_Pasajes (ePassenger list[], int len ){
    float suma_Precios;
    int i, cantidad_Pecios,promedio, superan;
    cantidad_Pecios=0;
    superan=0;


    for( i=0; i<len; i++ ){
	    if(list[i].isEmpty == OCUPADO ){
	        suma_Precios= suma_Precios+ list[i].price;
	        cantidad_Pecios ++;
	        }
    }

    promedio= (float) (suma_Precios/ cantidad_Pecios );

    for( i=0; i<len; i++ ){
	    if(list[i].isEmpty == OCUPADO && list[i].price>promedio ){
	       superan++;
	    }
    }

    printf ("\n ");
    printf ("\n --> El total de los precios de los pasajes es de  $ %.2f \n ",suma_Precios  );
    printf ("\n --> El promedio de los precios de los pasajes es de $ %d \n ",promedio  );
    printf ("\n --> La cantidad de pasajeros que superan el precio promedio de $ %d es %d \n", promedio, superan );

}

/// \fn void sortPassengersByCode(ePassenger[], int, eEstadoVuelo[])
/// \brief muestra listado de pasajeros por codigo y estado de vuelo ACTIVO
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \param estadoVuelo matriz de eEstadoVuelo
void sortPassengersByCode (ePassenger list[], int len, eEstadoVuelo estadoVuelo [] ){
    int i;
    printf ("\n --> Los pasajeros ingresados con estado de vuelo ACTIVO son... \n ");
    printf("\n  ID    |    NOMBRE   |   APELLIDO   |   PRECIO $   |   CODIGO DE VUELO  |  TIPO DE PASAJERO |  ESTADO DE VUELO  |  ");

    for( i=0; i<len; i++ ){
	    if( (list[i].isEmpty == OCUPADO) && (list[i].idStatusFlight == 1 )){
	        for(int j=0; j<2; j++)
	         if (1 == estadoVuelo[j].idStatusFlight ){
	                printf("\n %4d    %10s   %10s   %15.2f   %15s  %20d  %16s  \n",list[i].id,
	                                                                               list[i].name,
	                                                                               list[i].lastName,
	                                                                               list[i].price,
	                                                                               list[i].flycode,
	                                                                               list[i].idTypePassenger,
	                                                                               estadoVuelo[j].statusFlight);
	    }
     }

  }
}
