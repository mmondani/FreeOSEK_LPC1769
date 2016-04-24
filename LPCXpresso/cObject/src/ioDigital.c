#include "ioDigital.h"
#include "ioDigital_r.h"


static void* ioDigital_ctor  (void* _this, va_list* va);
static void* ioDigital_dtor (void* _this);
static uint32_t ioDigital_differ (void* _this, void* _dst);
static void ioDigital_display (void* _this);
static void* ioDigital_copy (void* _this, void* _src);
static uint32_t ioDigital_init (void* _this, va_list* va);
static uint32_t ioDigital_deInit (void* _this);
static uint32_t ioDigital_enable (void* _this);
static uint32_t ioDigital_disable (void* _this);
static uint32_t ioDigital_read (void* _this);
static uint32_t ioDigital_write (void* _this, uint32_t data);



// ********************************************************************************
// Declaración de la clase cStaticBuffer
// ********************************************************************************
static const struct ioObject _ioGPIO = {{sizeof(struct ioGPIO),
											ioDigital_ctor,
											ioDigital_dtor,
											ioDigital_differ,
											ioDigital_display,
											ioDigital_copy},
											ioDigital_init,
											ioDigital_deInit,
											ioDigital_enable,
											ioDigital_disable,
											ioDigital_read,
											ioDigital_write};

const void* ioGPIO = &_ioGPIO;
// ********************************************************************************



static void* ioDigital_ctor  (void* _this, va_list* va)
{
	// Constructor de la clase que es heredada
	return (((const struct cObject*) ioGPIO)->ctor (_this, va));

}


static void* ioDigital_dtor (void* _this)
{
	// Destructor de la clase que es heredada
	return (((const struct cObject*) ioGPIO)->dtor (_this));

}


static uint32_t ioDigital_differ (void* _this, void* _dst)
{
	// differ de la clase que es heredada
	return (((const struct cObject*) ioGPIO)->differ (_this, _dst));

}


static void ioDigital_display (void* _this)
{
	// display de la clase que es heredada
	((const struct cObject*) ioGPIO)->display (_this);

}


static void* ioDigital_copy (void* _this, void* _src)
{
	// copy de la clase que es heredada
	return (((const struct cObject*) ioGPIO)->copy (_this, _src));

}


static uint32_t ioDigital_init (void* _this, va_list* va)
{
	struct ioDigital* this = _this;

	GPIO_SetDir(port(this), 1UL << pin(this), direction(this));

	if (direction(this) == OUTPUT)
		(activeLevel(this) == LOW)? GPIO_ClearValue(port(this), 1UL << pin(this)) : GPIO_SetValue(port(this), 1UL << pin(this));


	return 0;
}


static uint32_t ioDigital_deInit (void* _this)
{
	return 0;
}


static uint32_t ioDigital_enable (void* _this)
{
	return 0;
}


static uint32_t ioDigital_disable (void* _this)
{
	return 0;
}


static uint32_t ioDigital_read (void* _this)
{
	uint32_t portValue = GPIO_ReadValue(port(_this));

	return ((portValue >> (1UL * pin(_this))) & 1UL);
}


static uint32_t ioDigital_write (void* _this, uint32_t data)
{
	if (data != 0)
	{
		GPIO_SetValue(port(_this), 1UL << pin(_this));
	}
	else
	{
		GPIO_ClearValue(port(_this), 1UL << pin(_this));
	}

	return 0;
}





// ********************************************************************************
// Métodos linkeados estáticamente a la clase ioDigital
// ********************************************************************************

uint32_t ioDigital_isActive (void* _this)
{
	uint32_t portValue = GPIO_ReadValue(port(_this));

	return (((portValue >> (1UL * pin(_this))) & 1UL) == activeLevel(_this))? 1 : 0;
}


void ioDigital_toggle (void* _this)
{
	if (direction(_this) == OUTPUT)
	{
		if (((GPIO_ReadValue(port(_this)) >> (1UL * pin(_this))) & 1UL) == 0)
			ioDigital_write (_this, HIGH);
		else
			ioDigital_write (_this, LOW);
	}
}
