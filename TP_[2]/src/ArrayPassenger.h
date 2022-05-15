#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>


//TIPO PASAJERO
typedef struct{

	int idTypePassenger;
    char typePassenger [30];// 1 calse turista-- 2 clase premium
}eTipoPasajero;


//ESTADO VUELO
typedef struct{

	int idStatusFlight;
    char statusFlight [30]; // 1. ACTIVO 2. EN ESPERA
}eEstadoVuelo;


//DATOS PASAJERO
typedef struct{

	int id; // identificacion mediante la cual accedo al nombre y apellido , datos gral
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];

    int idTypePassenger;

    int idStatusFlight;

    int isEmpty;

}ePassenger;
/*----------------------------------------------------------------------------------------------------*/
//DEFINO ESTRUCTURAS


//INICIALIZACION
int initPassengers(ePassenger list[], int len);
int addPassenger (ePassenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int idStatusFlight);


//ALTAS
ePassenger PedirDatos_Album (eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo []);
int Buscar_EspacioLibre (ePassenger list[],  int len );
int Alta_EspacioLibre (ePassenger list[],  int len , eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo [] );


//LISTAR
void printPassenger (ePassenger list[] , int len );
void  MostrarUnTicket(ePassenger list);

//MODIFICAR
int Ingreso_id (ePassenger list[] , int len);
int findPassengerById(ePassenger list[], int len,int id);
int Menu_Modificar (void);
void Modificar_DatosPasajero (ePassenger list[] , int len , eTipoPasajero tipoPasajero [] , eEstadoVuelo estadoVuelo []  );

//ELIMINAR
void removePassenger (ePassenger list[], int len,int id);
void Baja_Pasajero (ePassenger list[], int len );

//ORDENAR
int Ascendente_Descendente (void );
void Ascendente (ePassenger list[], int len, eTipoPasajero tipoPasajero []);
void Descendente (ePassenger list[], int len, eTipoPasajero tipoPasajero [] );
void sortPassengers(ePassenger list[] , int len, int order, eTipoPasajero tipoPasajero [] );

//ORDENAR-total y promedio precios pasajes, cuantos superan promedio
void Total_Promedio_Pasajes (ePassenger list[], int len );
void  sortPassengersByCode (ePassenger list[], int len , eEstadoVuelo estadoVuelo []  );


#endif /* ARRAYPASSENGER_H_ */
