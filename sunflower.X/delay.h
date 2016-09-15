/*
 *  Antônio Matheus Martins Cardoso
 *  João Gabriel dos Santos Gonçalves
 *  Alan Rabelo Martins
 * 
 *  Useful Delay
 */

#ifndef DELAY_H
#define DELAY_H

void delay_1ms();
void delay_1ms2();
void delay_Xms2();
void delay_serial();
void delay_beginSerial();

void delay_1ms() {
    int count = 0;
    while(count < 53) {
        count++;
    }
    _asm
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    _endasm

}

void delay_1ms2() {
    int count = 0;
    while(count < 47) {
        count++;
    }
}

void delay_Xms(int x) {
    int count = 0;
    while(count < x) {
        delay_1ms2();
        count++;
    }
}

void delay_serial() {
    int count = 0;
    while(count < 44) {
        count++;
    }
    
    _asm
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    _endasm
}

void delay_beginSerial() {
    int count = 0;
    while(count < 22) {
        count++;
    }
    
    _asm
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    _endasm
}

#endif /* DELAY_H */

