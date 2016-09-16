/*
 *  Antônio Matheus Martins Cardoso
 *  João Gabriel dos Santos Gonçalves
 *  Alan Rabelo Martins
 * 
 *  Main Program
 */

#include <p18f4550.h>
#include "serial.h"
#include "servo.h"

void setup();
void loop();

void main() {
    
    setup();
    
    while(1) {
        loop();
    }
}

void setup() {
    serial_setup();
    servo_setup();
} 

void loop() {
    char byte = serial_receiveByte();
    
    //R100P
    //R100T
    
    if(byte == 'R') {
        char ce = serial_receiveByte();
        char de = serial_receiveByte();
        char un = serial_receiveByte();
        
        char servo = serial_receiveByte();
    }
}
