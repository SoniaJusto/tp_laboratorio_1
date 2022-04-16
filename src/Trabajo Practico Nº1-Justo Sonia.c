/*
 ============================================================================
 Name        : Trabajo Practico N°1
 Author      : Justo Sonia
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones_Propias.H"
#include "Validaciones.H"
#include "Calculos.H"


int main ()
{
  setbuf (stdout, NULL);

  int opcionSeleccionada;
  int kmingresados;
  float precioAerolineas;
  float precioLatam;
  int contadorIngreso;
  int contadosKm;
  int calcularCostos;

  kmingresados=0;
  contadorIngreso=0;
  contadosKm=0;
  calcularCostos=0;

  do
    {

      /*MENU DE OPCIONES*/
      opcionSeleccionada= MenuYopcionSeleccionada (kmingresados, precioAerolineas,  precioLatam );

      switch (opcionSeleccionada)
	{
	  /*KM INGRESADOS POR USUARIO */
	  case 1:
	  if (contadosKm==0){
	      kmingresados = IngreseKm ( );
	  }else{
	      kmingresados= Validar_NuevoIngresado ( kmingresados);
	  }

	  contadosKm++;
	  break;

	  /*PRECIO DE VUELOS INGRESADOS POR USUARIO  */
	  case 2:
	  if (contadorIngreso==0){
	    precioAerolineas=  PrecioVueloAerolineas ( );
        precioLatam =  PrecioVueloLatam ();
	  }else{
	     precioAerolineas= Validar_PrecioAerolineas (precioAerolineas);
	     precioLatam= Validar_PrecioLatam (precioLatam);
	  }
      contadorIngreso++;
	  break;

	  /*CALCULAR COSTOS */
	  case 3:
	  CalcularCostos (precioLatam, precioAerolineas, kmingresados  );
	  calcularCostos++;
	  break;

	  /*INFORMAR COSTOS */
	  case 4:
	  if ( calcularCostos>0){
		 CalculosLatam ( precioLatam , kmingresados , precioAerolineas );
	  }else{
		  printf ("\n PARA VISUALIZAR LOS COSTOS DEBERA CALCULARLOS PRIMERO  INGRESANDO A LA OPCION N%c3", 248);
	  }

	  break;

	  /* CARGA FORZADA --> km=7090 // aerolineas= 162956 // latam= 159339*/
	  case 5:
      KmCargaForzada ( 7090 ) ;
	  CargaForzadaLatam ( 159339 , 7090 );
      CargaForzadaAerolineas( 162956, 7090 );
	  break;

	  /*SALIR */
	  case 6:
	  printf ("\n\n Muchas Gracias por utilizar nuestros servicios! ");
	  break;

	  default:
	  printf ("\n   < < < LA OPCI%cN INGRESADA NO ES VALIDA... INTENTE NUEVAMENTE > > >\n", 162);
	  printf ("\n-----------------------------------------------------------------------");
	  opcionSeleccionada=  MenuYopcionSeleccionada ( kmingresados, precioAerolineas, precioLatam );
	  break;

	}
      /* Fin */
    } while (opcionSeleccionada != 6);

  return 0;
}










