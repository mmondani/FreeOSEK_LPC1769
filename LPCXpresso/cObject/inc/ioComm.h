#ifndef IOCOMM_H_
#define IOCOMM_H_


#include "ioObject.h"


// ********************************************************************************
// Métodos públicos de la interfaz ioComm : ioObject
// ********************************************************************************


/*
 * ioComm_writeBytes
 *
 * Envía la cantidad de bytes len del buffer data.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 * 	   len: cantidad de bytes a enviar.
 * 	   data: buffer que contiene los bytes a enviar.
 *
 * 	<- Devuelve la cantidad de bytes realmente enviados.
 */
uint32_t ioComm_writeBytes (void* _this, uint32_t len, uint8_t* data);


/*
 * ioComm_readBytes
 *
 * Recibe la cantidad de bytes len en el buffer data.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 * 	   len: cantidad de bytes a recibir.
 * 	   data: buffer donde se van a guardar los bytes recibidos.
 *
 * 	<- Devuelve la cantidad de bytes realmente recibidos.
 */
uint32_t ioComm_readBytes (void* _this, uint32_t len, uint8_t* data);


/*
 * ioComm_freeSpace
 *
 * Devuelve la cantidad de espacio disponible en el buffer de salida
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 *
 * 	<- cantidad de bits disponibles
 */
uint32_t ioComm_freeSpace (void* _this);


/*
 * ioComm_dataAvailable
 *
 * Devuelve la cantidad de bytes para ser leídos.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 *
 * 	<- cantidad de bytes para ser leídos.
 */
uint32_t ioComm_dataAvailable (void* _this);


/*
 * ioComm_intEnable
 *
 * Habilita las interrupciones indicadas en mask.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 * 	   mask: máscara de las interrupciones unidas por ORs. Las definiciones
 * 	         de las interrupciones disponibles se deben buscar en el header de la
 * 	         clase que implementa esta interfaz.
 *
 */
void	 ioComm_intEnable (void* _this, uint32_t mask);


/*
 * ioComm_intDisable
 *
 * Deshabilita las interrupciones indicadas en mask.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 * 	   mask: máscara de las interrupciones unidas por ORs. Las definiciones
 * 	         de las interrupciones disponibles se deben buscar en el header de la
 * 	         clase que implementa esta interfaz.
 *
 */
void	 ioComm_intDisable (void* _this, uint32_t mask);


/*
 * ioComm_getInt
 *
 * Devuelve si la interrupción intID se produjo o no.
 *
 * 	-> _this: instancia de una clase que implementa a ioComm.
 * 	   intID: identificación de la interrupción. Las identficaciones de las interruciones
 * 	          se deben buscar en el header de la clase que implementa esta interfaz.
 *
 * 	<- 0 no se produjo la interrupción.
 * 	   1 se produjo la interrupción.
 */
uint32_t ioComm_getInt (void* _this, uint32_t intID);


#endif
