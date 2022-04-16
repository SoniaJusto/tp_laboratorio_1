/*
 * Funciones_Propias.c
 *
 *  Created on: 15 abr. 2022
 *      Author: sonia
 */

#include "Funciones_Propias.H"
#include "Validaciones.H"
#include "Calculos.H"

	/**
	  * \fn int MenuYopcionSeleccionada(int, float, float)
	 * \brief
	 * \pre
	 * \param kmingresados
	 * \param precioAerolineas
	 * \param precioLatam
	 * \return opcion seleccionada por usuario
	 */

   int MenuYopcionSeleccionada (int kmingresados, float precioAerolineas, float precioLatam ){

	int opcionSeleccionada;
	printf ("\n-----------------------------------------------------------------------");
	printf ("\n  *** MENU DE OPCIONES: ***   ");
	printf ("\n 1. Ingresar Kil%cmetros (km = %d ) ", 162 ,kmingresados );
	printf ("\n 2. Ingresar Precio de Vuelos (Aerolineas Argentinas = $ %.2f >>  Latam= $ %.2f )",precioAerolineas ,precioLatam );
	printf ("\n 3. Calcular todos los costos ");
	printf ("\n 4. Informar Resultados ");
	printf ("\n 5. Carga forzada de datos ");
	printf ("\n 6. Salir ");
	printf ("\n\n   Introduzca una opci%cn (1-6): ", 162);
	scanf ("%d", &opcionSeleccionada);

    return opcionSeleccionada;
    }

   /**
    * \fn int IngreseKm()
    * \brief
    * \pre
    * \post
    * \return km ingresados por usuario previa validacion
    */
    int IngreseKm ( ){

    int kmIngresados;
    kmIngresados=0;

    printf ("\n 1. Ingresar Kil%cmetros ( Km = %d ) : ", 162 , kmIngresados);
	scanf ("%d", &kmIngresados);

	while (kmIngresados <1 ){
	  printf ("\n Lo ingresado es NO ES VALIDO. (Los Km no deben ser negativo ni 0) ");
	  printf ("\n\n 1. Ingresar Kil%cmetros:  ", 162);
      scanf ("%d", &kmIngresados);
	}
    printf ("\n-----------------------------------------------------------------------");
	return kmIngresados;
    }

    /**
     * \fn float PrecioVueloAerolineas()
     * \brief
     * \pre
     * \post
     * \return precio del vuelo por Aerolineas ingresado por usuario previa validacion
     */
    float PrecioVueloAerolineas ( ){

    float precioAerolineas;
    printf ("\n  Ingresar Precio de Vuelos : ");
    printf ("\n a. Precio vuelo Aerolineas Argentinas : $ " );
    scanf ("%f", &precioAerolineas);

    while (precioAerolineas <1 ){
	  printf ("\n Lo ingresado NO ES VALIDO. (El precio ($) NO debe ser negativo ) ");
	  printf ("\n a. Precio vuelo Aerolineas Argentinas : $ ");
      scanf ("%f", &precioAerolineas);
    }
    return precioAerolineas;
    }

    /**
     * \fn float PrecioVueloLatam()
     * \brief
     * \pre
     * \post
     * \return precio del vuelo por Latam ingresado por usuario previa validacion
     */

    float PrecioVueloLatam ( ){

    float precioLatam;
    printf ("\n b. Precio vuelo Latam: $ ");
    scanf ("%f", &precioLatam);

    while (precioLatam <1 ){
	  printf ("\n Lo ingresado NO ES VALIDO. (El $ no debe ser negativo ) ");
	  printf ("\n b. Precio vuelo Latam: $ ");
      scanf ("%f", &precioLatam);
    }
    printf ("\n-----------------------------------------------------------------------");
    return precioLatam;
    }

    /**
     * \fn void CalcularCostos(float, float, int)
     * \brief
     * \pre
     * \param precioLatam
     * \param precioAerolineas
     * \return
     */

    void CalcularCostos (float precioLatam, float precioAerolineas , int kmingresados ) {

    if  ( precioAerolineas <1 || precioLatam <1 ||  kmingresados<1  ){
        printf (" \n ERROR!... DEBERA CARGAR PREVIAMENTE LOS DATOS SOLICITADOS EN LA <Opci%cn N1 y N2>",162 );
    } else {
    	printf ("\n LOS COSTOS HAN SIDO CALCULADOS CORRECTAMENTE! ");
    	printf ("\n\n a) Tarjeta de d%cbito (descuento 10 %c ) ", 130, 37);
    	printf ("\n b) Tarjeta de cr%cdito (inter%cs 25 %c ) ", 130, 130 , 37 );
    	printf ("\n c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) ");
    	printf ("\n d) Mostrar precio por km (precio unitario) ");
    	printf ("\n e) Mostrar diferencia de precio ingresada (Latam - Aerol%cneas) " , 161);
    	printf("\n\n PODRA VISUALIZAR LOS MISMOS INGRESANDO A LA <Opci%cn Nº 4>", 162);
    }
     printf ("\n\n-----------------------------------------------------------------------");
     }

    /**
     * \fn void CalculosLatam(float, int, float)
     * \brief
     * \pre
     * \param precioLatam
     * \param kmingresados
     * \param precioAerolineas
     * \return costo del pasaje por Aerolineas y Latam pagando con diferentes formas de pago
     */
    void CalculosLatam  ( float precioLatam , int kmingresados , float precioAerolineas){

   if (precioLatam<1 ||kmingresados<1  ){
       printf ("\n\n Para calcular los costos debera ingresar los KM (Opcion N1) y el PRECIO DE LOS VUELOS ( Opcion N2) >");

   }else{
       printf ("\n Latam: (Km: %d / Precio: $ %.2f)  ",kmingresados, precioLatam );
       Latam_Debito ( precioLatam );
       Latam_Credito ( precioLatam );
       Latam_BTC( precioLatam );
       Latam_Unitario( precioLatam, kmingresados );

	   CalculosAerolineas ( precioAerolineas,  kmingresados,  precioLatam );
   }
   }
    /**
     * \fn void CalculosAerolineas(float, int, float)
     * \brief
     * \pre
     * \param precioAerolineas
     * \param kmingresados
     * \param precioLatam
     * \return costo del pasaje por Aerolineas pagando con diferentes formas de pago
     */

    void CalculosAerolineas ( float precioAerolineas, int kmingresados, float precioLatam ){

    printf (" \n\n Aerol%cneas: (Km: %d / Precio: $ %.2f ) ",161, kmingresados, precioAerolineas );
    Aerolineas_Debito ( precioAerolineas );
    Aerolineas_Credito ( precioAerolineas );
    Aerolineas_BTC ( precioAerolineas );
    Aerolineas_Unitario ( precioAerolineas , kmingresados );

    Diferencia_Precio ( precioLatam ,  precioAerolineas);

    printf ("\n\n-----------------------------------------------------------------------");
    }

    /**
     * \fn void KmCargaForzada(int)
     * \brief
     * \pre
     * \param km
     * \return km carga forzada
     */

   void KmCargaForzada ( int km ) {
    printf ("\n Kms Ingresados: %d km ", km);
    }

   /**
    * \fn void CargaForzadaLatam(float, int)
    * \brief
    * \pre
    * \param latam
    * \param km
    * \return precio del pasaje Latam pagando con diferentes formas de pago
    */
    void CargaForzadaLatam ( float latam , int km ){

    printf ("\n Latam: ");

    CargaForzada_LatamDebito (latam);
    CargaForzada_LatamCredito (latam);
    CargaForzada_LatamBTC (latam);
    CargaForzada_LatamPunitario (latam , km );

    }

    /**
     * \fn void CargaForzadaAerolineas(float, int)
     * \brief
     * \pre
     * \param aerolineas
     * \param km
     * \ return precio del pasaje Aerolineas pagando con diferentes formas de pago
     */
    void CargaForzadaAerolineas( float aerolineas, int km ){

    printf ("\n\n Aerolineas: ");
    CargaForzada_AerolineasDebito (aerolineas);
    CargaForzada_AerolineasCredito (aerolineas);
    CargaForzada_AerolineasBTC (aerolineas);
    CargaForzada_AerolineasPunitario (aerolineas , km );

	printf ("\n\n-----------------------------------------------------------------------");
    }
