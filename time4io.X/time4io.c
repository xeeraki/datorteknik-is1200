/* 
 * File:   time4io.c
 * Author: shafai
 *
 * Created on August 8, 2017, 1:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include "mipslab.h"

int getsw(void){
    int *sw4,*sw3,*sw2,*sw1;
    int *switches = PORTD= 0xf00; 
    
    if(!switches){
    *sw4 = PORTDbits.RD11 = 1;
    *sw3 = PORTDbits.RD10 = 1;
    *sw2 = PORTDbits.RD9 = 1;
    *sw1 = PORTDbits.RD8 = 1;
    }
    
    return switches;
}


