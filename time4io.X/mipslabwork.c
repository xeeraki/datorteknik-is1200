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
    *trise &= ~0xff;
    
    TRISD = ~0xfe0;
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
    int i;
  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  volatile int *porte = (volatile int*) 0xbf886110;
  volatile int *LED = (volatile int*) 0xbf886110;
  while(1){
      
        *LED = (*porte = 0xff);
        tick( &mytime );
         *LED = (*porte = 0xfe);
        tick( &mytime );
         *LED = (*porte = 0xfd);
        tick( &mytime );
        *LED = (*porte = 0xfc); 
        tick( &mytime );
         *LED = (*porte = 0xfb);
        tick( &mytime );
         *LED = (*porte = 0xf8);
        tick( &mytime );
         *LED = (*porte = 0xf7);
        tick( &mytime );
         *LED = (*porte = 0xf0);
        tick( &mytime );
         *LED = (*porte = 0xef);
        tick( &mytime );
         *LED = (*porte = 0xe0);
        tick( &mytime );
         *LED = (*porte = 0xdf);
        tick( &mytime );
         *LED = (*porte = 0xc0);
        tick( &mytime );
         *LED = (*porte = 0xbf);
        tick( &mytime );
         *LED = (*porte = 0x80);
        tick( &mytime );
         *LED = (*porte = 0x7f);
        tick( &mytime );
         *LED = (*porte = 0x00);
      
  
       
          
      }
  
  display_image(96, icon);
}