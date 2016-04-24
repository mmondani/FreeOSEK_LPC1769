#ifndef CSTATICBUFFER_R_H
#define CSTATICBUFFER_R_H


#include "cBuffer_r.h"


struct cStaticBuffer
{
	const void* class;
	void* buffer;
	uint32_t len;
	size_t objectSize;
};

// Macros de get y set para ser usados de forma privada por la clase cStaticBuffer
// y por las que la heredan
#define buffer(p)		(((const struct cStaticBuffer*)p)->buffer)
#define len(p)			(((const struct cStaticBuffer*)p)->len)
#define objectSize(p)	(((const struct cStaticBuffer*)p)->objectSize)

#define set_buffer(p, v)			(((struct cStaticBuffer*)p)->buffer = (v))
#define set_len(p, v)				(((struct cStaticBuffer*)p)->len = (v))
#define set_objectSize(p, v)		(((struct cStaticBuffer*)p)->objectSize = (v))



#endif
