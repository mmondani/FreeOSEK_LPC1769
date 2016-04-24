#ifndef IOOBJECT_H_
#define IOOBJECT_H_


#include "cObject.h"
#include "chip.h"



// ********************************************************************************
// Métodos públicos de la interfaz ioObject : cObject
// ********************************************************************************


/*
 * ioObject_init
 *
 * Inicializa el hardware relacionado con el ioObject.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 *
 * 	<- Duelve 0 si la inicialización fue exitosa. Otro valor si hubo un error.
 */
uint32_t ioObject_init (void* _this);


/*
 * ioObject_deInit
 *
 * Des-inicializa el hardware asociado al iObject.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 *
 * 	<- Duelve 0 en caso de éxito. Otro valor si hubo un error.
 */
uint32_t ioObject_deInit (void* _this);


/*
 * ioObject_enable
 *
 * Habilita el periférico.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 *
 * 	<- Duelve 0 en caso de éxito. Otro valor si hubo un error.
 */
uint32_t ioObject_enable (void* _this);


/*
 * ioObject_disable
 *
 * Deshabilita el periférico.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 *
 * 	<- Duelve 0 en caso de éxito. Otro valor si hubo un error.
 */
uint32_t ioObject_disable (void* _this);


/*
 * ioObject_read
 *
 * Lee un valor desde el periférico.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 *
 * 	<- Valor leido.
 */
uint32_t ioObject_read (void* _this);


/*
 * ioObject_write
 *
 * Escribe un valor al periférico.
 *
 * 	-> _this: instancia de una clase que implementa a ioObject.
 * 	-> data: valor a escribir.
 *
 * 	<- Duelve 0 en caso de éxito. Otro valor si hubo un error.
 */
uint32_t ioObject_write (void* _this, uint32_t data);

// ********************************************************************************

#endif
