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
#include "ioUART.h"

void* uart3;
const uint8_t* str1 = "Hola mundo!\r\n";

void SysTick_Handler(void)
{
	ioComm_writeBytes(uart3, sizeof ("Hola mundo\n\r"), str1);
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

    uart3 = cObject_new(ioUART, LPC_UART3, IOUART_BR_9600, IOUART_DATA_8BIT, IOUART_PAR_NONE, IOUART_STOP_1BIT, IOUART_MODE_BLOCKING, 50, 50);
    ioObject_init(uart3);
    //ioUART_configFIFO(uart3, IOUART_FIFO_LEVEL0);



    SysTick_Config(SystemCoreClock / 10);


    while(1)
    {
    }


    return 0 ;
}
