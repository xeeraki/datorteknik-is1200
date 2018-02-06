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
	 printf("%10d \n", n);



}

int is_prime(int n){
    //for loop för att hitta tal som inte är primtal
	for(int i = 2; i < n; i++){
	if(n % i == 0 && n!=i)
    return 0;
}
  return 1;
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  int c = 0;
  for(int i = 2; i < n; i++)
  {

	  if(is_prime(i)){
	  print_number(i);
	  c++;
      }
      if(c == COLUMNS)
      {
		  printf("\n");
		  c=0;
      }

  }
}
// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}


