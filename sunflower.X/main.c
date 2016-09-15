/*
 *  Antônio Matheus Martins Cardoso
 *  João Gabriel dos Santos Gonçalves
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
