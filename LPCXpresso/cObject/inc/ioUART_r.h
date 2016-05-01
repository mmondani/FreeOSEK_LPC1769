#ifndef IOUART_R_H
#define IOUART_R_H


#include "ioComm_r.h"


struct ioUART
{
	const void* class;
	void* periphMem;
	uint32_t baudRate;
	uint32_t dataLen;
	uint32_t parity;
	uint32_t stopBit;
	uint32_t mode;
	void* txQueue;
	void* rxQueue;
};


// Macros de get y set para ser usados de forma privada por ioUART y las clases que la heredan
#define periphMem(p)			(((const struct ioUART*)p)->periphMem)
#define baudRate(p)			    (((const struct ioUART*)p)->baudRate)
#define dataLen(p)			    (((const struct ioUART*)p)->dataLen)
#define parity(p)			    (((const struct ioUART*)p)->parity)
#define stopBit(p)			    (((const struct ioUART*)p)->stopBit)
#define mode(p)			        (((const struct ioUART*)p)->mode)
#define txQueue(p)			    (((const struct ioUART*)p)->txQueue)
#define rxQueue(p)			    (((const struct ioUART*)p)->rxQueue)

#define set_periphMem(p, v)			(((struct ioUART*)p)->periphMem = (v))
#define set_baudRate(p, v)			(((struct ioUART*)p)->baudRate = (v))
#define set_dataLen(p, v)			(((struct ioUART*)p)->dataLen = (v))
#define set_parity(p, v)			(((struct ioUART*)p)->parity = (v))
#define set_stopBit(p, v)			(((struct ioUART*)p)->stopBit = (v))
#define set_mode(p, v)			    (((struct ioUART*)p)->mode = (v))
#define set_txQueue(p, v)			(((struct ioUART*)p)->txQueue = (v))
#define set_rxQueue(p, v)			(((struct ioUART*)p)->rxQueue = (v))



#endif
