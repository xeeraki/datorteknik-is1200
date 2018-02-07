/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):
   Love Pelz 2018-02-03

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#define TM2PERIOD (80000000 / 256) / 10 // 10 timeouts per secound

int prime = 1234567;
int timeoutcount = 0;
int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void ) {
	timeoutcount++;

if(timeoutcount == 10){
 time2string( textstring, mytime );
 display_string( 3, textstring );
 display_update();
 tick( &mytime );
 timeoutcount = 0;
}
IFSCLR(0) = 0x100; //clear flag before returning from isr
}


/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int *trise = (volatile int*) 0xbf886100;
  *trise = *trise & 0xff00; // set bits 0 to 7 to output
  TRISD = 0x0fe0; // set bits 5 to 11 to input

  PR2 = TM2PERIOD; // set defined period
  T2CONSET = 0x70; // set prescaler to 1:256
  TMR2 = 0; //reset timer
  T2CONSET = 0x8000; // bit 15 starts timer

  IPC(2) = IPC(2)| 0x10; // enable interupt from timer 2 ,priority 7 (interrupt priority control)
  IEC(0) = 0x100; // set bit for interupt to be enabled (interrupt enable control)
  enable_interrupt(); // enable interrupt globally

  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
prime = nextprime( prime );
display_string(0, itoaconv(prime));
display_update();
 }



