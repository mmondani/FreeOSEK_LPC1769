#ifndef CQUEUE_R_H_
#define CQUEUE_R_H_

#include "cStaticBuffer_r.h"

struct cQueue
{
	struct cStaticBuffer _;
	uint32_t ptrIn;
	uint32_t ptrOut;
	uint32_t type;
};


// Macros de get y set para ser usados de forma privada por cQueue y las clases que la heredan
#define ptrIn(p)					(((const struct cQueue*)p)->ptrIn)
#define ptrOut(p)					(((const struct cQueue*)p)->ptrOut)
#define type(p)					    (((const struct cQueue*)p)->type)

#define set_ptrIn(p, v)			    (((struct cQueue*)p)->ptrIn = (v))
#define set_ptrOut(p, v)			(((struct cQueue*)p)->ptrOut = (v))
#define set_type(p, v)			    (((struct cQueue*)p)->type = (v))

#endif
