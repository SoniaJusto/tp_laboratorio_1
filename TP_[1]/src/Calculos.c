/*
 * Calculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: sonia
 */

#include "Validaciones.H"
#include "Funciones_Propias.H"
#include "Calculos.H"

/**
 * \fn void Latam_Debito(float)
 * \brief
 * \pre
 * \param precioLatam equivale al precio del pasaje con la empresa de nombre "LATAM"
 * \return precio del pasaje por la empresa Latam pagando con Tarjeta de Debito
 */
 void Latam_Debito ( float precioLatam ){
	 float debitoLatam;
	 debitoLatam = (precioLatam - ((10 * precioLatam) / 100));
	 printf ("\n a) Precio con Tarjeta de D%cbito: $ %.2f ", 130, debitoLatam);
 }
 /**
  * \fn void Latam_Credito(float)
  * \brief
  * \pre
  * \param precioLatam  equivale al precio del pasaje con la empresa de nombre "LATAM"
  * \return precio del pasaje por la empresa Latam pagando con Tarjeta de Credito
  */

 void Latam_Credito (float precioLatam ){
	 float creditoLatam;
	 creditoLatam = (precioLatam + ((25 * precioLatam) / 100));
	 printf ("\n b) Precio con Tarjeta de Cr%cdito: $ %.2f ", 130, creditoLatam);
 }

/**
 * \fn void Latam_BTC(float)
 * \brief
 * \pre
 * \param precioLatam equivale al precio del pasaje con la empresa de nombre "LATAM"
 * \return precio del pasaje por la empresa Latam pagando con Bitcoin
 */
 void Latam_BTC( float precioLatam ){
	 float bitcoinLatam;
	 bitcoinLatam = (precioLatam / 4606954.55 );
	 printf ("\n c) Precio pagando con Bitcoin (BTC) : $ %.5f " , bitcoinLatam);
 }
/**
 * \fn void Latam_Unitario(float, int)
 * \brief
 * \pre
 * \param precioLatam equivale al precio del pasaje con la empresa de nombre "LATAM"
 * \param kmingresados equivale a los km ingresados
 * \return precio por Km-Latam
 */

 void Latam_Unitario(float precioLatam ,int kmingresados ){
	 float precioUnitarioLatam;
	 precioUnitarioLatam= (precioLatam / kmingresados  );
	 printf ("\n d) Precio Unitario: $ %.2f  ", precioUnitarioLatam  );

 }
 /**
   * \fn void Diferencia_Precio(float, float)
  * \brief
  * \pre
  * \param precioLatam  equivale al precio del pasaje con la empresa de nombre "LATAM"
  * \param precioAerolineas equivale al precio del pasaje con la empresa de nombre "AEROLINEAS ARGENTINAS"
  * \return diferencia de precio entre el pasaje de LATAM con el de AEROLINEAS
  */

 void Diferencia_Precio (float precioLatam , float precioAerolineas){
      float resta;
      resta = (precioLatam-precioAerolineas );

        if (resta <0){
    	   resta = resta*-1;
    	}

      printf ("\n \n La diferencia de precio es de : $ %.2f ", resta);
    }
/**
 * \fn void Aerolineas_Debito(float)
 * \brief
 * \pre
 * \param precioAerolineas equivale al precio del pasaje con la empresa de nombre "AEROLINEAS ARGENTINAS"
 * \return precio del pasaje por la empresa Aerolineas Argentinas pagando con Tarjeta de Debito
 */

 void Aerolineas_Debito ( float precioAerolineas ){
	    float debitoAerolineas;
	    debitoAerolineas = (precioAerolineas - ((10 * precioAerolineas) / 100));
	    printf ("\n a) Precio con Tarjeta de D%cbito: $ %.2f ", 130, debitoAerolineas);
 }

/**
 * \fn void Aerolineas_Credito(float)
 * \brief
 * \pre
 * \param precioAerolineas equivale al precio del pasaje con la empresa de nombre "AEROLINEAS ARGENTINAS"
 * \return precio del pasaje por la empresa Aerolineas Argentinas pagando con Tarjeta de Credito
 */
 void Aerolineas_Credito ( float precioAerolineas ){
	    float creditoAerolineas;
		creditoAerolineas = (precioAerolineas + ((25 * precioAerolineas) / 100));
	    printf ("\n b) Precio con Tarjeta de Cr%cdito: $ %.2f ", 130, creditoAerolineas);
 }

/**
 * \fn void Aerolineas_BTC(float)
 * \brief
 * \pre
 * \param precioAerolineas equivale al precio del pasaje con la empresa de nombre "AEROLINEAS ARGENTINAS"
 * \return precio del pasaje por la empresa Aerolineas Argentinas pagando con Bitcoin
 */
 void Aerolineas_BTC (float precioAerolineas ){
	    float bitcoinAerolineas;
		bitcoinAerolineas = (precioAerolineas / 4606954.55 );
	    printf ("\n c) Precio pagando con Bitcoin (BTC) : $ %.5f ", bitcoinAerolineas);
 }

/**
 * \fn void Aerolineas_Unitario(float, int)
 * \brief
 * \pre
 * \param precioAerolineas equivale al precio del pasaje con la empresa de nombre "AEROLINEAS ARGENTINAS"
 * \param kmingresados equivale a los Km ingresados
 * \return precio por Km-Aerolineas
 */
 void Aerolineas_Unitario ( float precioAerolineas ,int  kmingresados ){
	    float precioUnitarioAerolines;
		precioUnitarioAerolines= (precioAerolineas / kmingresados  );
	    printf ("\n d) Precio Unitario: $ %.2f ",precioUnitarioAerolines );
 }


/**
 * \fn void CargaForzada_LatamDebito(float)
 * \brief
 * \pre
 * \param latam carga forzada del valor pasaje por LATAM
 * \return precio del pasaje por la empresa LATAM  pagando con Tarjeta de Debito
 */
 void CargaForzada_LatamDebito (float latam){
	    float debitoL;
	    debitoL = (latam - ((10 * latam) / 100));
	    printf ("\n a) Precio con Tarjeta de D%cbito: $ %.2f ", 130, debitoL );
 }
/**
 * \fn void CargaForzada_LatamCredito(float)
 * \brief
 * \pre
 * \param latam carga forzada del valor pasaje por LATAM
 * \return precio del pasaje por la empresa LATAM  pagando con Tarjeta de Credito
 */
 void CargaForzada_LatamCredito (float latam){
	    float creditoL;
		creditoL = (latam + ((25 * latam) / 100));
		printf ("\n b) Precio con Tarjeta de Cr%cdito: $ %.2f ", 130,  creditoL );
 }
/**
 * \fn void CargaForzada_LatamBTC(float)
 * \brief
 * \pre
 * \param latam carga forzada del valor pasaje por LATAM
 * \return precio del pasaje por la empresa LATAM  pagando con Bitcoin
 */
 void CargaForzada_LatamBTC (float latam){
	    float bitcoinL;
	    bitcoinL = (latam / 4606954.55 );
		printf ("\n c) Precio pagando con Bitcoin (BTC) : $ %.5f " , bitcoinL );
 }
/**
 * \fn void CargaForzada_LatamPunitario(float, int)
 * \brief
 * \pre
 * \param km carga forzada de los km
 * \param latam carga forzada del valor pasaje por LATAM
 * \return precio por Km-Latam
 */
 void CargaForzada_LatamPunitario ( float latam , int km ){
	    float PrecioUnitarioL;
	    PrecioUnitarioL= ( latam / km );
		printf ("\n d) Precio Unitario: $ %.2f ", PrecioUnitarioL );
 }
/**
 * \fn void CargaForzada_AerolineasDebito(float)
 * \brief
 * \pre
 * \param aerolineas carga forzada del valor pasaje por AEROLINEAS
 * \return precio del pasaje por la empresa AEROLINEAS  pagando con Tarjeta de Debito
 */

 void CargaForzada_AerolineasDebito (float aerolineas){
	    float debitoAA;
	    debitoAA  = (aerolineas - ((10 * aerolineas) / 100));
		printf ("\n a) Precio con Tarjeta de D%cbito: $ %.2f ", 130,  debitoAA);
 }
/**
 * \fn void CargaForzada_AerolineasCredito(float)
 * \brief
 * \pre
 * \param aerolineas carga forzada del valor pasaje por AEROLINEAS
 * \return precio del pasaje por la empresa AEROLINEAS pagando con Tarjeta de Credito
 */

 void CargaForzada_AerolineasCredito (float aerolineas){
	 float creditoAA;
	 creditoAA = (aerolineas + ((25 * aerolineas) / 100));
	 printf ("\n b) Precio con Tarjeta de Cr%cdito: $ %.2f ", 130, creditoAA);
 }

 /**
   * \fn void CargaForzada_AerolineasBTC(float)
  * \brief
  * \pre
  * \param aerolineas carga forzada del valor pasaje por AEROLINEAS
  * \return precio del pasaje por la empresa AEROLINEAS pagando con Bitcoin
  */
 void CargaForzada_AerolineasBTC (float aerolineas){
     float bitcoinAA;
 	 bitcoinAA = (aerolineas / 4606954.55 );
     printf ("\n c) Precio pagando con Bitcoin (BTC) : $ %.5f ",bitcoinAA );
 }

/**
 * \fn void CargaForzada_AerolineasPunitario(float, int)
 * \brief
 * \pre
 * \param km carga forzada de los Km
 * \param aerolineas carga forzada del valor pasaje por AEROLINEAS
 * \return precio Km-Aerolineas
 */
 void CargaForzada_AerolineasPunitario (float aerolineas ,int km ){
     float PrecioUnitarioA;
     PrecioUnitarioA= ( aerolineas / km );
 	 printf ("\n d) Precio Unitario: $ %.2f ", PrecioUnitarioA );
 }


