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

int timeoutc = 0;
int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
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

  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{

   volatile int* LED = (volatile int*) 0xbf886110;
  int switches;
  int buttons;

  while(1){
  buttons = getbtns();
  switches = getsw();

  //binary value of btn2 is 2
  if(buttons == 2){
  mytime = mytime & 0xff0f;
  mytime = (switches << 4)| mytime; //change left secound to switch binary value
  }

  if(buttons == 4){
  mytime = mytime & 0xf0ff;
  mytime = (switches << 8)| mytime; //change right minute to switch binary value
  }

  if(buttons == 8)
  {
  mytime = mytime & 0x0fff;
  mytime = (switches << 12) | mytime; //change left minute to switch binary value
  }
 if(IFS(0) & 0x100){   // check for time-out event flag

 	timeoutc ++;
 	IFSCLR(0) = 0x100; //clear timeout flag
 }
 if(timeoutc == 10){ // update time after 10 timeouts, meaning it updates time after each secound
   time2string( textstring, mytime );
   display_string( 3, textstring );
   display_update();
   tick( &mytime );
   display_image(96, icon);
   *LED = *LED + 0x1;
   timeoutc = 0;
}


 }



}
