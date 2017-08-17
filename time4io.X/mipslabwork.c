/* 
 * File:   mipslabwork.c
 * Author: shafai
 *
 * Created on August 5, 2017, 7:15 PM
 */

#include <stdio.h>
#include <stdlib.h>

/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog 

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <p32xxxx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

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
    //volatile int *porte = (volatile int*) 0xbf88611f;
    //volatile int *LED = (volatile int*) 0xbf886100;
    *trise &= ~0x00ff;
    //0000 1111 1110 0000
    TRISD = 0x0fe0;
    /*
    while(1){
        *LED = (*porte = 0xff);
    }
     */
    return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  volatile int *porte = (volatile int*) 0xbf886110;
  volatile int *LED = (volatile int*) 0xbf886110; 
  
   int sw;
   int btn;
   while(1){
       delay(1000);
       sw = getsw();
       btn = getbtns();
       //button 4 (0100)
       if(btn == 4){
       mytime = mytime & 0x0fff;
       mytime = (sw<<12) | mytime ;
       }
       //button 3 (0010)
       if(btn == 2){
       mytime = mytime & 0xf0ff;
       mytime = (sw<<8) | mytime ;
       }
       //button 2 (0001)
       if(btn == 1){
       mytime = mytime & 0xff0f;
       mytime = (sw<<4) | mytime ;
       }
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick(&mytime);
  display_image(96, icon);
  *LED = *LED + 0x1;
   }
   
  delay(1000);
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick(&mytime);
  display_image(96, icon);
} 


 
/*
  int btn4Pressed = PORTD = 0x0080;
  int btn3Pressed = PORTD = 0x0040;
  int btn2Pressed = PORTD = 0x0020;
  
  
  int sw4Polled = PORTD = 0x0800;
  int sw3Polled = PORTD = 0x0400;
  int sw2Polled = PORTD = 0x0200;
  //int *sw1Polled = PORTD = 0x0100;
  while(1){
      delay(1000);
  if(btn4Pressed){
      mytime = mytime & (sw4Polled<<4); //0x5957 & 0x800(0101 1001 0101 0111 & 0000 1000 0000 0000)
  } 
      if (btn3Pressed){
          mytime = mytime & sw3Polled;
      }
      if (btn2Pressed){
          mytime = mytime & (sw2Polled>>4);
      }    
  }
  */
