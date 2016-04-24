#ifndef IOOBJECT_R_H_
#define IOOBJECT_R_H_

#include "cObject_r.h"


struct ioObject
{
	struct cObject _;
	uint32_t (*init) (void* _this);
	uint32_t (*deInit) (void* _this);
	uint32_t (*enable) (void* _this);
	uint32_t (*disable) (void* _this);
	uint32_t (*read) (void* _this);
	uint32_t (*write) (void* _this, uint32_t data);
};

#endif
