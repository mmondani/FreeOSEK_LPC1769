#ifndef IOCOMM_R_H_
#define IOCOMM_R_H_

#include "ioObject_r.h"


struct ioComm
{
	struct ioObject _;
	uint32_t (*writeBytes) (void* _this, uint32_t len, uint8_t* data);
	uint32_t (*readBytes) (void* _this, uint32_t len, uint8_t* data);
	uint32_t (*freeSpace) (void* _this);
	uint32_t (*dataAvailable) (void* _this);
	void	 (*intEnable) (void* _this, uint32_t mask);
	void	 (*intDisable) (void* _this, uint32_t mask);
	uint32_t (*getInt) (void* _this, uint32_t intID);
};

#endif
