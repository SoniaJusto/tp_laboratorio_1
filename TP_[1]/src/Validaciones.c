/*
 * Validaciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: sonia
 */


#include "Validaciones.H"
#include "Funciones_Propias.H"
#include "Calculos.H"

	/**
    * \fn int Validar_NuevoIngresado(int)
	 * \brief
	 * \pre
	 * \post
	 * \param kmingresados KM (INGRESADO POR EL USUARIO)
	 * \return nuevo valor del Km (PREVIA ACEPTACION DEL USUARIO Y POSTERIOR VALIDACION DE LO INGRESADO)
	 */
	int Validar_NuevoIngresado (int kmingresados) {
    char respuesta;
    int km;
        printf ("\n Ud. ya ha ingresado:  %d km  ",kmingresados );
        printf ("\n Desea ingresar nuevos valores ?... S/N :" );
        scanf ("%c", &respuesta);

         switch (respuesta =getchar()){
           case 's':
           case 'S':
           km= Ingrese_OtroKm (kmingresados );
           break;

         case 'n':
         case 'N':
         km= kmingresados;
         break;
        }
        return km;
        printf ("\n-----------------------------------------------------------------------");
    }
	/**
    * \fn int Ingrese_OtroKm(int)
	 * \brief
	 * \pre
	 * \post
	 * \param kmingresados KM ingresados por el usuario anteriormente
	 * \return nuevo valor del Km
	 */

    int Ingrese_OtroKm (int kmingresados ){
    printf ("\n 1. Ingresar Kil%cmetros (km = %d)  : ", 162 , kmingresados);
	scanf ("%d", &kmingresados);

	while (kmingresados <1 ){
	  printf ("\n Lo ingresado NO ES VALIDO. (Los Km no deben ser negativo ni 0) ");
	  printf ("\n\n 1. Ingresar Kil%cmetros:  ", 162);
      scanf ("%d", &kmingresados);
	}
    printf ("\n-----------------------------------------------------------------------");
	return kmingresados;
    }

    /**
     * \fn float Validar_PrecioAerolineas(float)
     * \brief
     * \pre
     * \post
     * \param precioAerolineas precio del vuelo por la empresa Aerolinea Argentinas (INGRESADO POR EL USUARIO)
     * \return nuevo valor del precio del pasaje por Aerolineas (PREVIA ACEPTACION DEL USUARIO Y POSTERIOR VALIDACION DE LO INGRESADO)
     */
	float Validar_PrecioAerolineas (float precioAerolineas) {
    char respuesta;
    float precio;

    printf ("\n Ud. ya ha ingresado el precio de un vuelo por la empresa Aerolineas Argentinas de $  %.2f  ",precioAerolineas );
    printf ("\n Desea ingresar un nuevo valor ?... S/N :" );
    scanf ("%c", &respuesta);

      switch (respuesta =getchar()){

       case 'S':
       case 's':
        precio=  Ingrese_OtroPrecioAerolineas ( precioAerolineas );
       break;

       case 'n':
       case 'N':
        precio=precioAerolineas ;
       break;
      }
      return precio;
      printf ("\n-----------------------------------------------------------------------");
   }

	/**
	 * \fn float Ingrese_OtroPrecioAerolineas(float)
	 * \brief
	 * \pre
	 * \post
	 * \param precioAerolineas precio del vuelo por la empresa Aerolinea Argentinas (INGRESADO POR EL USUARIO)
	 * \return  nuevo valor del precio del vuelo por Aerolineas
	 */
	float Ingrese_OtroPrecioAerolineas (float precioAerolineas ){

	    printf ("\n a. Precio vuelo Aerolineas Argentinas:" );
	    scanf ("%f", &precioAerolineas);

	    while (precioAerolineas <1 ){
		  printf ("\n Lo ingresado NO ES VALIDO. (El precio ($) NO debe ser negativo ) ");
		  printf ("\n a. Precio vuelo Aerolineas Argentinas : $ ");
	      scanf ("%f", &precioAerolineas);
	    }
	    return precioAerolineas;
	    }

	/**
	 * \fn float Validar_PrecioLatam(float)
	 * \brief
	 * \pre
	 * \post
	 * \param precioLatam precio del vuelo por la empresa Latam (INGRESADO POR EL USUARIO)
	 * \return nuevo valor del precio del pasaje por Latam (PREVIA ACEPTACION DEL USUARIO Y POSTERIOR VALIDACION DE LO INGRESADO)
	 */
	 float Validar_PrecioLatam (float precioLatam){
     char respuesta;
     float precio;
     printf ("\n Tambien hemos encontrado que ha ingresado un precio para su viaje por la Empresa Latam :  %.2f  $  ",precioLatam );
     printf ("\n Desea ingresar un nuevo valor ?... S/N :" );
     scanf ("%c", &respuesta);

      switch (respuesta =getchar()){
       case 's':
       case 'S':
        precio= Ingrese_OtroPrecioLatam ( precioLatam );
       break;

       case 'n':
       case 'N':
        precio= precioLatam ;
       break;
        }
        printf ("\n-----------------------------------------------------------------------");
        return precio;
    }

	 /**
	  * \fn float Ingrese_OtroPrecioLatam(float)
	  * \brief
	  * \pre
	  * \post
	  * \param precioLatam  precio del vuelo por la empresa Latam (INGRESADO POR EL USUARIO)
	  * \return  nuevo valor del precio del pasaje por Latam
	  */
	 float Ingrese_OtroPrecioLatam (float precioLatam ){

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
