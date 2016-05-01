#ifndef CBUFFER_R_H_
#define CBUFFER_R_H_

#include "cObject_r.h"


struct cBuffer
{
	struct cObject _;
	void* (*put) (void* _this, void* _object);
	void* (*remove) (void* _this, void* _object);
	void* (*clear) (void* _this);
	void (*at) (void* _this, uint32_t pos, void* _object);
	uint32_t (*getFreeSpace) (void* _this);
	uint32_t (*getPending) (void* _this);
	uint32_t (*length) (void* _this);
};

#endif
