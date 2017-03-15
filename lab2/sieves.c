#include<stdio.h>
#include<stdlib.h>
#define COLUMNS 6
#define MAX_PRIMES 105

void print_sieves(int max[]){
	int max = [MAX_PRIMES];
	//samllest_prime is p = 2
	int p = 2;
	for(int i = 2; i < MAX_PRIMES;i++){
		//if p is multiple of 2p, 3p ... mark them out but not p it self
		if((max[i]*p)%2 == 0){
			max[i]= 2;
			// look for the next i value which is not multiple of p 
		else if((max[i] * p)%2 == 1){
			p++;
			print_number(p);
			}
		} 
	}
}
void print_number(int n){
	int i;
		printf("%10d\t",n);
		if(i % COLUMNS == 0){
		printf("\n");
			i++;	
		}
}
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
    //print_primes(105);
  return 0;
  
}

