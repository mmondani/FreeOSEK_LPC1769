#ifndef IOGPIO_R_H
#define IOGPIO_R_H


#include "ioObject_r.h"


struct ioGPIO
{
	const void* class;
	void* periphMem;
	uint32_t direction;
	uint32_t port;
	uint32_t pin;
};

// Macros de get y set para ser usados de forma privada por las clases que implementan
// la interfaz ioGPIO
#define periphMem(p)			(((const struct ioGPIO*)p)->periphMem)
#define direction(p)			(((const struct ioGPIO*)p)->direction)
#define port(p)					(((const struct ioGPIO*)p)->port)
#define pin(p)					(((const struct ioGPIO*)p)->pin)

#define set_periphMem(p, v)			(((struct ioGPIO*)p)->periphMem = (v))
#define set_direction(p, v)			(((struct ioGPIO*)p)->direction = (v))
#define set_port(p, v)				(((struct ioGPIO*)p)->port = (v))
#define set_pin(p, v)				(((struct ioGPIO*)p)->pin = (v))



#endif
