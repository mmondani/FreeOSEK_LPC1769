#include "cBuffer.h"
#include "cBuffer_r.h"



void* cBuffer_put (void* _this, void* _object)
{
	const struct cBuffer* const * class = _this;

	if (_this && class && (*class)->put)
	{
		_this = ((*class)->put(_this, _object));
	}

	return _this;
}


void* cBuffer_remove (void* _this, void* _object)
{
	const struct cBuffer* const * class = _this;

	if (_this && class && (*class)->remove)
	{
		_this = ((*class)->remove(_this, _object));
	}

	return _this;
}


void* cBuffer_clear (void* _this)
{
	const struct cBuffer* const * class = _this;

	if (_this && class && (*class)->clear)
	{
		_this = ((*class)->clear(_this));
	}

	return _this;
}


void cBuffer_at (void* _this, uint32_t pos, void* _object)
{
	const struct cBuffer* const * class = _this;

	if (_this && class && (*class)->at)
	{
		((*class)->at(_this, pos, _object));
	}
}
