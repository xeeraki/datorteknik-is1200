/*
written by Adam Shafai
this code prints evrey third ascii charachter from 0 to F
this is converted from the assembly lab 1 written by F. Lundevall
*/

#include <stdio.h>
int main(void)
{
	int i;
	for(i = 0x30; i < 0x5b; i=i+3)
	printf("%c" , i);



}
