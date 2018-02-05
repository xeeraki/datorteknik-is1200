/* 
 * File:   time4io.c
 * Author: shafai
 *
 * Created on August 14, 2017, 7:08 PM
 */

#include <stdint.h>
#include <p32xxxx.h>
#include "mipslab.h" 

int getsw( void ){

	int SW = (PORTD >> 8) & 0x000F;

	return SW;
}

int getbtns(void){

	int BTN = (PORTD >> 5) & 0x0007;

	return BTN;
}