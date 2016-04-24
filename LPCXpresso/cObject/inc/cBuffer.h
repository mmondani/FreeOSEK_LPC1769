#ifndef CBUFFER_H_
#define CBUFFER_H_


#include "cObject.h"


// ********************************************************************************
// Métodos públicos de la interfaz cBuffer : cObject
// ********************************************************************************


/*
 * cBuffer_put
 *
 * Agrega un elemento del buffer _this.
 *
 * 	-> _this: buffer al que agregar el elemento _object.
 * 	-> _object: elemento a agregar.
 *
 * 	<- Puntero al buffer _this. Permite concatenar el llamado de funciones.
 */
void* cBuffer_put (void* _this, void* _object);


/*
 * cBuffer_remove
 *
 * Elimina un elemento del buffer _this.
 *
 * 	-> _this: buffer del que se elimina un elemento.
 *
 * 	<- Puntero al buffer _this. Permite concatenar el llamado de funciones.
 */
void* cBuffer_remove (void* _this, void* _object);


/*
 * cBuffer_clear
 *
 * Limpia el buffer _this.
 *
 * 	-> _this: buffer a limpiar.
 *
 * 	<- Puntero al buffer _this. Permite concatenar el llamado de funciones.
 */
void* cBuffer_clear (void* _this);


/*
 * cBuffer_at
 *
 * Devuelve el elemento en la posición pos del buffer _this.
 *
 * 	-> _this: buffer.
 * 	-> pos: posición del elemento a devolver. Se numera desde 0.
 * 	-> _object: elemento en la posición pos del buffer _this.
 *
 */
void cBuffer_at (void* _this, uint32_t pos, void* _object);

#endif
