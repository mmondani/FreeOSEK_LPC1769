#ifndef IODIGITAL_H_
#define IODIGITAL_H_

#include "ioGPIO.h"




// ********************************************************************************
// Instanciación de ioDigital
//
// void* digitalPin = cObject_new(ioDigital, periphMem, direction, port, pin)
// ********************************************************************************
extern const void* ioDigital;



// ********************************************************************************
// Métodos públicos de la clase ioDigital : ioGPIO
// ********************************************************************************

/*
 * ioDigital_toggle
 *
 * Hace un toggle del estado del pin digital (si es salida).
 *
 * 	-> _this: pin digital.
 *
 */
void ioDigital_toggle (void* _this);
// ********************************************************************************


#endif
