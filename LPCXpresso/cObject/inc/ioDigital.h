#ifndef IODIGITAL_H_
#define IODIGITAL_H_

#include "ioGPIO.h"



enum {LOW = 0, HIGH};
enum {INPUT = 0, OUTPUT};

// ********************************************************************************
// Instanciación de ioDigital
//
// void* digital = cObject_new(ioDigital, periphMem, direction, activeState, port, pin)
// ********************************************************************************
extern const void* ioDigital;



// ********************************************************************************
// Métodos públicos de la clase ioDigital : ioGPIO
// ********************************************************************************
uint32_t ioDigital_isActive (void* _this);
void ioDigital_toggle (void* _this);
// ********************************************************************************


#endif
