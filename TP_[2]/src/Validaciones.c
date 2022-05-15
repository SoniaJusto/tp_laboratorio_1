#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "Validaciones.h"

#define CANT 50
#define LIBRE 0
#define OCUPADO 1

/// \fn int MenuOpciones(char[])
/// \brief indica opciones del menu principal
/// \param menu char
/// \return opcion seleccionada del menu principal

int MenuOpciones (char menu []){
    int opcion;

    printf ("%s", menu);
    scanf ("%d", &opcion);

    while (opcion < 1  || opcion>  6 ){
      printf ("\n\t INCORRECTO!! ...\n\t Introduzca una opcion (1-6): ");
      scanf ( " %d", &opcion);
    }

    printf("\n");
    return opcion;
}

/// \fn float Validar_precio()
/// \brief solicta ingreso del precio del vuelo
/// \return precio del vuelo validado
float  Validar_precio (){
    float precio;

    printf ("\n Ingrese el precio del vuelo:  ");
    scanf (" %f", &precio  );

    while (precio <=0 ){
      printf ("\n\t INCORRECTO!!.. (El precio NO puede ser negativo) ");
	  scanf(" %f", &precio);
    }

    return precio;
}

/// \fn int ValidarTipoPasajero(eTipoPasajero[])
/// \brief solicta ingreso del valor referente al tipo de pasajero
/// \param tipoPasajero matriz de eTipoPasajero
/// \return valor de la variable referente al tipo de pasajero seleccionado
int ValidarTipoPasajero (eTipoPasajero tipoPasajero []){
    int Tpasajero;

    printf ("\n Ingrese el tipo de pasajero :\n ");
    for (int i=0; i<2; i++){
      printf ("\t| %3d  |  %10s  \n  ",tipoPasajero [i].idTypePassenger,tipoPasajero [i].typePassenger  );
    }
    printf ("\n Introduzca el N° correspondiente al << Tipo de Pasajero >>: " );
    scanf("%d", &Tpasajero);

    while (Tpasajero!= 1 &&  Tpasajero != 2 ){
        printf ("\n INCORRECTO!! ...\n ");
        for (int i=0; i<2; i++){
           printf ("\t| %3d  |  %10s  \n  ",tipoPasajero [i].idTypePassenger,tipoPasajero [i].typePassenger  );
    }
    printf ("\n Introduzca el N° correspondiente al << Tipo de Pasajero >>: " );
    scanf("%d", &Tpasajero);

    }

    return Tpasajero;
}

/// \fn int Validar_estadoVuelo(eEstadoVuelo[])
/// \brief solicita ingreso del valor referente al estado del vuelo
/// \param estadoVuelo matriz de eEstadoVuelo
/// \return  valor de la variable referente al estado del vuelo seleccionado
int Validar_estadoVuelo (eEstadoVuelo estadoVuelo []){
    int estado;

    printf ("\n Ingrese el estado del vuelo :\n ");
    for (int i=0; i<2; i++){
      printf ("\t| %3d  |  %10s  \n  ",estadoVuelo [i].idStatusFlight ,estadoVuelo [i].statusFlight  );
    }
    printf ("\n Introduzca el N° correspondiente al <<Estado del Vuelo >>: " );
    scanf("%d", &estado);

    while (estado != 1 && estado != 2 ){
        printf ("\n INCORRECTO!! ...\n ");
        for (int i=0; i<2; i++){
           printf ("\t| %3d  |  %10s  \n  ",estadoVuelo[i].idStatusFlight ,estadoVuelo [i].statusFlight  );
    }
    printf ("\n Introduzca el N° correspondiente al << Estado del Vuelo >>: " );
    scanf("%d", &estado);
    }
    return estado;
    }

/// \fn int ValidarId_Amodificar(ePassenger[], int)
/// \brief solicita ingreso de id
/// \param list matriz de ePassenger
/// \param int len Longitud de la matriz
/// \return valor de id previa validacion
int ValidarId_Amodificar (ePassenger list[] , int len ){
    int id;

    printf("\n Recuerde ... \n  ");
    printf("\n   |       ID       |        NOMBRE      |\n ");

     for (int i=0; i<len; i++)
     if ( list[i].isEmpty == OCUPADO ){
     printf("  \t %5d    %17s  \n  ", list[i].id , list[i].name);
	}

	printf ("\n Ingrese en Nº de Id del pasajero  : ");
    scanf(" %d", &id);

    return id;
}

/// \fn int Valida_Menu()
/// \brief informa opciones posibles de modificacion
/// \return opcion seleccionada
int Valida_Menu(){
   int opcion;
    printf ("\n\t INDIQUE QUE DATOS DESEA MODIFICAR ... \n");
    printf ("\n\t 1. Nombre :");
    printf ("\n\t 2. Apellido: ");
    printf ("\n\t 3. Precio: ");
    printf ("\n\t 4. Tipo de Pasajero : ");
    printf ("\n\t 5. C%cdigo de vuelo: ", 162);
    printf ("\n\t 6. Salir ");
    printf ("\n\n  Introduzca una opcion (1-6): ");
    scanf ( " %d", &opcion);

    while (opcion < 1  || opcion>  6 ){
      printf ("\n\t INCORRECTO!! ...\n\t Introduzca una opcion (1-6): ");
      scanf ( " %d", &opcion);
    }

    return opcion;

}

/// \fn int Validar_Ascendente_Descendente()
/// \brief informa opciones posibles de visualizacion del listado de pasajeros
/// \return opcion seleccionada
int Validar_Ascendente_Descendente ( ){
    int opcion;

    printf ("\n Indique en que orden desea visualizar el listado de pasajeros ");
    printf ("\n\t 1. Ascendente " );
    printf ("\n\t 2. Descendente " );
    printf ("\n\t 3. Salir " );
    printf ("\n\n Indique opcion (1-3): " );
    scanf (" %d", &opcion);

     while (opcion < 1  || opcion>  3 ){
      printf ("\n\t INCORRECTO!! ...\n\t Introduzca una opcion (1-3): ");
      scanf ( " %d", &opcion);
    }

    return opcion;


}
