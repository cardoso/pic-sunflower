/*
 *  Ant�nio Matheus Martins Cardoso
 *  Jo�o Gabriel dos Santos Gon�alves
 *  Alan Rabelo Martins
 * 
 *  Main Program
 */

#include <p18f4550.h>
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
    servo_setup();
} 

void loop() {

}
