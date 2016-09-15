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
#include <delays.h>


unsigned char servo_degrees;

void servo_degrees_delay();


#pragma interrupt servo_handle_interruption
void servo_handle_interruption() {
    
    unsigned char i = 0;
    
    // set timer to 20ms
    TMR0L = 227;
    TMR0H = 21;
    
    // reset timer flag
    INTCONbits.TMR0IF = 0;
    
    // start servo wave
    PORTCbits.RC0 = 1;
    
    // start 1ms delay
    Delay100TCYx(28);
    Delay10TCYx(18);
    Nop();
    Nop();
    Nop();
    Nop();
    
    
    // 1 degree delay
    
    while(i < servo_degrees) {
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        i++;
    }
    // stop 1ms delay
    
    PORTCbits.RC0 = 0;
}

#pragma code servo_high_level_interruption = 0x8
void servo_high_level_interruption() {
    _asm goto servo_handle_interruption _endasm
}

void servo_degrees_delay() {
    char i = 0;
    while(i < servo_degrees) {
        i++;
    }
}

void servo_setup() {
    TRISC = 0;
    INTCONbits.GIE = 1;
    
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_EDGE_RISE & T0_PS_1_1);
    
    // set timer to 20ms
    TMR0L = 227;
    TMR0H = 21;
    
    // precision = 0-250
    servo_degrees = 249;
}

#endif	/* PWM_H */

