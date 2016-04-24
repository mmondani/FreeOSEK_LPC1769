#ifndef COBJECT_R_H_
#define COBJECT_R_H_


#include <stdint.h>
#include <stdarg.h>

struct cObject
{
	int32_t size;
	void* (*ctor) (void* _this, va_list* va);
	void* (*dtor) (void* _this);
	uint32_t (*differ) (void* _this, void* _dst);
	void (*display) (void* _this);
	void* (*copy) (void* _this, void* _src);
};




//#define NO_ASSERT

#ifdef NO_ASSERT
#define assert(expr)
#else
#define assert(expr) 		\
{ 							\
    if (!(expr))			\
    { 						\
        while(1);			\
    } 						\
}
#endif

#endif
