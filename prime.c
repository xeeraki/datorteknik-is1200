/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>

int is_prime(int n){
//my code begins here

int p; 	
//Defination of prime is it must be diviseble with itself and 1 		(Wikipedia)
	for(p = 2; p < n; p++){
		if(n % p ==0 && p != n)
		return 0;	
	}
  return 1;
 //my code finish here
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
