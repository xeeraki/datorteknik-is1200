/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COLUMNS 6
	
void print_number(int n){
	int i;
		printf("%10d\t",n);
		if(i % COLUMNS == 0){
		printf("\n");
			i++;	
		}
}
/*
int is_prime(int n){
	int p; 	
	for(p = 2; p < n; p++){
		if(n % p ==0 && p != n)
			return 0;	
	}
  	return 1;
}
*/
void print_sieves(int n){
int *A = malloc(sizeof(int)*n);
	int i,j;
	for(i =2; i < n; i++){
	A[i] = 1;
	}
	 for(i = 2; i < n; i++){
	    if(A[i]){
	      for(j= i+1; j < n; j++){
		if(j%i == 0){
	    A[j] = 0;
				}
			}	
		}
	}
	for(i =2; i <= n; i++){
	if(A[i]){
		print_number(i);
		}
	}
		printf("\n");	
	free(A);
}
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
    //print_primes(105);
  return 0;
  
}
