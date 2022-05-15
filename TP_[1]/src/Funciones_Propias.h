/*
 * Funciones_Propias.h
 *
 *  Created on: 15 abr. 2022
 *      Author: sonia
 */

#ifndef FUNCIONES_PROPIAS_H_
#define FUNCIONES_PROPIAS_H_
#include <stdio.h>

int MenuYopcionSeleccionada (int kmingresados, float precioAerolineas, float precioLatam );
void CalcularCostos (float precioLatam, float precioAerolineas , int kmingresados );
int IngreseKm ( );
float PrecioVueloAerolineas ( );
float PrecioVueloLatam ();
void CalculosLatam  ( float precioLatam , int kmingresados, float precioAerolineas);
void CalculosAerolineas ( float precioAerolineas , int kmingresados ,float precioLatam ) ;
void KmCargaForzada ( int km ) ;
void CargaForzadaLatam (float latam , int km );
void CargaForzadaAerolineas( float aerolineas , int km);
void Diferencia_Precio (float precioLatam , float precioAerolineas);


#endif /* FUNCIONES_PROPIAS_H_ */
