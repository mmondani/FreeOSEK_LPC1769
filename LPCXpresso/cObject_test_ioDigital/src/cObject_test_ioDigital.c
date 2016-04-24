/*
===============================================================================
 Name        : cObject_test_ioDigital.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>
#include "memAlloc.h"
#include "cObject.h"
#include "ioDigital.h"

void* pinLed;


void SysTick_Handler(void)
{
	ioDigital_toggle(pinLed);
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    initMemHeap();

    pinLed = cObject_new(ioDigital, LPC_GPIO, IOGPIO_OUTPUT, 0, 22);
    ioObject_init(pinLed);

    SysTick_Config(SystemCoreClock / 20);


    while(1)
    {
    }


    return 0 ;
}
