/* 
 * File:   time4io.c
 * Author: shafai
 *
 * Created on August 14, 2017, 7:08 PM
 */

#include <stdint.h>
#include <p32xxxx.h>
#include "mipslab.h" 

int getsw(void){
    //(11 to 8) = 0x0f00 = 0000 1111 0000 0000
    int switches = (PORTD>>8) & 0x000f;
    
    return switches;
   
}

int getbtns(void){
   
    // (7 to 5) = 0x00e0 = 0000 0000 1110 0000
    int buttons = (PORTD>>5) & 0x0007;
      
    return buttons;
}
