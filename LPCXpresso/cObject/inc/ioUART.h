#ifndef IOUART_H
#define IOUART_H

#include "ioComm.h"
#include "cQueue.h"



// ********************************************************************************
// Instanciación de ioUART
//
// void* uart = cObject_new(ioUART, periphMem, baudRate, dataLen, parity, stopBit, mode, txQueueLen, rxQueueLen)
// ********************************************************************************
extern const void* ioUART;



// ********************************************************************************
// Enumeraciones de la clase ioUART
// ********************************************************************************

enum { IOUART_BR_2400 = 2400,
	   IOUART_BR_4800 = 4800,
	   IOUART_BR_9600 = 9600,
	   IOUART_BR_19200 = 19200,
	   IOUART_BR_57600 = 57600,
	   IOUART_BR_115200 = 115200
};

enum { IOUART_DATA_5BIT = UART_LCR_WLEN5,
	    IOUART_DATA_6BIT = UART_LCR_WLEN6,
		IOUART_DATA_7BIT = UART_LCR_WLEN7,
		IOUART_DATA_8BIT = UART_LCR_WLEN8,
};

enum { IOUART_PAR_NONE = UART_LCR_PARITY_DIS,
	    IOUART_PAR_ODD = UART_LCR_PARITY_EN | UART_LCR_PARITY_ODD,
		IOUART_PAR_EVEN = UART_LCR_PARITY_EN | UART_LCR_PARITY_EVEN
};

enum { IOUART_STOP_1BIT = UART_LCR_SBS_1BIT,
	    IOUART_STOP_2BIT = UART_LCR_SBS_2BIT
};

enum { IOUART_FIFO_LEVEL0 = UART_FCR_FIFO_EN | UART_FCR_RX_RS | UART_FCR_TX_RS | UART_FCR_TRG_LEV0,		// 1 bytes en LPC17xx
	   IOUART_FIFO_LEVEL1 = UART_FCR_FIFO_EN | UART_FCR_RX_RS | UART_FCR_TX_RS | UART_FCR_TRG_LEV1,		// 4 bytes en LPC17xx
	   IOUART_FIFO_LEVEL2 = UART_FCR_FIFO_EN | UART_FCR_RX_RS | UART_FCR_TX_RS | UART_FCR_TRG_LEV2,		// 8 bytes en LPC17xx
	   IOUART_FIFO_LEVEL3 = UART_FCR_FIFO_EN | UART_FCR_RX_RS | UART_FCR_TX_RS | UART_FCR_TRG_LEV3		// 14 bytes en LPC17xx
};

enum { IOUART_MODE_BLOCKING = 0,
	    IOUART_MODE_NON_BLOCKING
};

enum { IOUART_INT_RX = UART_IER_RBRINT,
		IOUART_INT_TX = UART_IER_THREINT,
		IOUART_INT_RX_LINE_STATUS = UART_IER_RLSINT
};

enum { IOUART_INT_ID_RX = UART_IIR_INTID_RDA,
	    IOUART_INT_ID_TX = UART_IIR_INTID_THRE,
		IOUART_INT_UID_RX_LINE_STATUS = UART_IIR_INTID_RLS
};

// ********************************************************************************



// ********************************************************************************
// Métodos públicos de la clase ioUART
// ********************************************************************************

/*
 * ioUART_configFIFO
 *
 * Configura los niveles de interrupción de los FIFO de transmisión y recepción
 *
 * 	-> _this: instancia de la clase ioUART.
 * 	   config: parámetros de configuración unidos por ORs.
 *
 */
void ioUART_configFIFO (void* _this, uint32_t config);


/*
 * ioUART_rxHandler
 *
 * Método que debe ser llamado en el handler de la interrupción de recepción.
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_rxHandler (void* _this);


/*
 * ioUART_txHandler
 *
 * Método que debe ser llamado en el handler de la interrupción de transmisión.
 * Solo se va a llamar en el caso que la instancia de ioUART se haya configurado
 * para trabajar en modo NON_BLOCKING
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_txHandler (void* _this);


/*
 * ioUART_disableTx
 *
 * Deshabilita la transmisión de la UART.
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_disableTx (void* _this);


/*
 * ioUART_enableTx
 *
 * Habilita la transmisión de la UART.
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_enableTx (void* _this);


/*
 * ioUART_disableRx
 *
 * Deshabilita la recepción de la UART.
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_disableRx (void* _this);


/*
 * ioUART_enableRx
 *
 * Habilita la recepción de la UART.
 *
 * 	-> _this: instancia de la clase ioUART.
 *
 */
void ioUART_enableRx (void* _this);

// ********************************************************************************

#endif
