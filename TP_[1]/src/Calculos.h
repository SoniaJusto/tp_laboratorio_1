/*
 * Calculos.h
 *
 *  Created on: 16 abr. 2022
 *      Author: sonia
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>

void Latam_Debito (float  precioLatam );
void Latam_Credito (float precioLatam );
void Latam_BTC(float precioLatam );
void Latam_Unitario(float  precioLatam , int kmingresados );
void Diferencia_Precio (float precioLatam , float precioAerolineas);

void Aerolineas_Debito ( float precioAerolineas );
void Aerolineas_Credito ( float precioAerolineas );
void Aerolineas_BTC (float precioAerolineas );
void Aerolineas_Unitario ( float precioAerolineas ,int  kmingresados );

void CargaForzada_LatamDebito (float latam);
void CargaForzada_LatamCredito (float latam);
void CargaForzada_LatamBTC (float latam);
void CargaForzada_LatamPunitario ( float latam , int km );

void CargaForzada_AerolineasDebito (float aerolineas);
void CargaForzada_AerolineasCredito (float aerolineas);
void CargaForzada_AerolineasBTC (float aerolineas);
void CargaForzada_AerolineasPunitario (float aerolineas ,int km );


#endif /* CALCULOS_H_ */
