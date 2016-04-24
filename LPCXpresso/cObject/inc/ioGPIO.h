#ifndef IOGPIO_H
#define IOGPIO_H

#include "ioObject.h"
#include <stdint.h>
#include <string.h>


// ********************************************************************************
// Instanciación de ioGPIO
//
// void* gpio = cObject_new(ioGPIO, periphMem, direction, port, pin)
// ********************************************************************************
extern const void* ioGPIO;



// ********************************************************************************
// Enumeraciones de la interfaz ioGPIO : ioObject
// ********************************************************************************

enum {IOGPIO_INPUT = 0, IOGPIO_OUTPUT};

// ********************************************************************************



// ********************************************************************************
// Métodos públicos de la clase ioGPIO : ioObject
// ********************************************************************************

// ********************************************************************************

#endif
