#include <xc.h>
#include <stdbool.h>

#include "support_uart.h"

#ifdef _16F18877
#define UART_PIE    PIE3bits
#define UART_PIR    PIR3bits
#else
#define UART_PIE    PIE1bits
#define UART_PIR    PIR1bits
#endif

// disable watchdog
#pragma config WDTE = OFF

void putch(char data)
{
    TX1REG = data;
    UART_PIR.TXIF = 0;
}

void support_init_uart(void)
{
    // disable interrupts before changing states
    UART_PIE.RCIE = 0;
    UART_PIE.TXIE = 0;
    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUD1CON = 0x08;
    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RC1STA = 0x90;
    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TX1STA = 0x24;
    // SP1BRGL 138; 
    SP1BRGL = 0x8A;
    // SP1BRGH 0; 
    SP1BRGH = 0x00;

    RXPPS = 0x10;   //RC0->EUSART:RX;
    RC2PPS = 0x14;   //RC2->EUSART:TX;
}
