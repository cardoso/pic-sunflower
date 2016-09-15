/*
 *  Antônio Matheus Martins Cardoso
 *  João Gabriel dos Santos Gonçalves
 *  Alan Rabelo Martins
 * 
 *  Servo Program
 */

#ifndef SERVO_H
#define	SERVO_H

#include <timers.h> 
#include "delay.h"

#pragma interrupt servo_handle_interruption
void servo_handle_interruption() {
    
    // set timer to 20ms
    TMR0L = 237;
    TMR0H = 177;
    
    // reset timer flag
    INTCONbits.TMR0IF = 0;
    
    // do servo wave
    PORTCbits.RC0 = 1;
    delay_1ms();
    delay_1ms();
    PORTCbits.RC0 = 0;
}

#pragma code servo_high_level_interruption = 0x8
void servo_high_level_interruption() {
    _asm goto servo_handle_interruption _endasm
}

void servo_setup() {
    TRISC = 0;
    INTCONbits.GIE = 1;
    
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_EDGE_RISE & T0_PS_1_1);
    
    // set timer to 20ms
    TMR0L = 237;
    TMR0H = 177;
}

#endif	/* PWM_H */

