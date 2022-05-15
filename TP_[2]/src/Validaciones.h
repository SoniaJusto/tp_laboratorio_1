/*
 * Validaciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: sonia
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>

int MenuOpciones (char menu []);
float  Validar_precio (void);
int ValidarTipoPasajero (eTipoPasajero tipoPasajero []);
int Validar_estadoVuelo (eEstadoVuelo estadoVuelo []);
int ValidarId_Amodificar (ePassenger list[] , int len );
int Valida_Menu(void);
int Validar_Ascendente_Descendente (void );

#endif /* VALIDACIONES_H_ */
