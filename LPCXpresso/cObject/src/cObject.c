#include "cObject.h"
#include "cObject_r.h"


void* cObject_new (const void* _class, ...)
{
	const struct cObject* class = _class;

	void* p = memAlloc(class->size);

	*(const struct cObject**)p = class;

	if (class->ctor)
	{
		va_list va;

		va_start(va, _class);
		class->ctor(p, &va);
		va_end(va);
	}

	return p;
}


void cObject_delete (void* _this)
{
	const struct cObject** class = _this;

	if (_this && class && (*class)->dtor)
	{
		_this = ((*class)->dtor(_this));
	}

	memFree(_this);
}


uint32_t cObject_differ (void* _this, void* _dst)
{
	const struct cObject* const * class = _this;

	if (_this && class && (*class)->differ)
	{
		return ((*class)->differ(_this, _dst));
	}

	return 1;
}

void cObject_display (void* _this)
{
	const struct cObject* const * class = _this;

	if (_this && class && (*class)->display)
	{
		(*class)->display(_this);
	}
}


void* cObject_copy (void* _this, void* _src)
{
	const struct cObject* const * class = _this;
	void* p = 0;


	if (_this && class && (*class)->copy)
	{
		p = (*class)->copy(_this, _src);
	}

	return p;
}
