#ifndef COBJECT_H_
#define COBJECT_H_

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "memAlloc.h"



// ********************************************************************************
// Métodos públicos de la interfaz cObject
// ********************************************************************************


/*
 * cObject_new
 *
 * Crea un objeto perteneciente a la clase _class. Reserva la memoria requerida por el objeto (usando memAlloc)
 * y llama al constructor de la clase requerida y de las clases de las que hereda.
 *
 * 	-> _class: clase que se quiere instanciar. El identificador de cada clase esta en el
 * 	           archivo .h correspondiente a la clase.
 * 	-> ...: lista de parámetros dependiente de cada clase. Para ver cómo instanciar cada clase
 * 			referirse al .h de la clase.
 *
 * 	<- objeto creado.
 */
void* cObject_new (const void* _class, ...);


/*
 * cObject_delete
 *
 * Libera la memoria alocada con cObject_new
 *
 * 	-> _this: objeto que se quiere destruir.
 *
 */
void cObject_delete (void* _this);


/*
 * cObject_differ
 *
 * Determina si dos objetos son distintos.
 *
 * 	-> _this: primer objeto a comparar.
 * 	-> _dst: segundo objeto a comparar.
 *
 * 	<- 1 si son distintos, 0 si son iguales.
 */
uint32_t cObject_differ (void* _this, void* _dst);


/*
 * cObject_display
 *
 * Muestra el objeto _this
 *
 * 	-> _this: objeto a mostrar.
 *
 */
void cObject_display (void* _this);


/*
 * cObject_copy
 *
 * Copia un objeto a otro.
 *
 * 	-> _this: objeto destino de la copia.
 * 	-> _src: objeto origen de la copia.
 *
 * 	<- Puntero al objeto destino.
 */
void* cObject_copy (void* _this, void* _src);


// ********************************************************************************


#endif
