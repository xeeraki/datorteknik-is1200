/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 6

void print_number(int n){
	int i;
	for(i = 0; i <= n; i++){
		if(i % COLUMNS == 0)
		
		printf("\n");
		printf("%d\t",i);
		}
		printf("\n");
}
int is_prime(int n){
	int p; 	
	for(p = 2; p < n; p++){
		if(n % p ==0 && p != n)
			return 0;	
	}
  	return p;
}
void print_primes(int n){
	int primes;
	int i;
	for(i =0; i <= n; i++){
		if(is_prime(i) !=0){
		primes = is_prime(i);
		print_number(primes);
		}	
		
	}	
}
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
    print_primes(105);
  return 0;
  
}

 

