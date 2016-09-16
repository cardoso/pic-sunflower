/*
 *  Antônio Matheus Martins Cardoso
 *  João Gabriel dos Santos Gonçalves
 *  Alan Rabelo Martins
 * 
 *  Serial Program
 */

#ifndef SERIAL_H
#define	SERIAL_H

#include <delays.h>

#define RX_BIT PORTAbits.RA0

char serial_receiveByte();
void serial_delayBit();
void serial_delayBeginSerial();

char serial_receiveByte() {
    char byte = 0;
    
    while(RX_BIT) {}
    serial_delayBit();
    serial_delayBeginSerial();
    byte = RX_BIT;
    serial_delayBit();
    byte |= (RX_BIT << 1);
    serial_delayBit();
    byte |= (RX_BIT << 2);
    serial_delayBit();
    byte |= (RX_BIT << 3);
    serial_delayBit();
    byte |= (RX_BIT << 4);
    serial_delayBit();
    byte |= (RX_BIT << 5);
    serial_delayBit();
    byte |= (RX_BIT << 6);
    serial_delayBit();
    byte |= (RX_BIT << 7);
    serial_delayBit();
    
    return byte;
}

void serial_delayBit() {
    Delay1KTCYx(2);
    Delay100TCYx(4);
    Delay10TCYx(8);
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}

void serial_delayBeginSerial() {
    Delay1KTCYx(1);
    Delay100TCYx(2);
    Delay10TCYx(4);
    Nop();
    Nop();
    Nop();
    Nop();
}

void serial_setup() {
    ADCON1 = 0b00001111;
    TRISAbits.RA0 = 1;
}

#endif	/* SERIAL_H */
