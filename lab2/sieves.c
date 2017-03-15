#include<stdio.h>
#include<stdlib.h>
#define COLUMNS 6
#define MAX_PRIMES 500

void print_sieves(int n){
	int i, j, max [MAX_PRIMES];
	//samllest_prime is p = 2
	int p = 2;
	for(i = 2; i < n;i++){
		//if p is multiple of 2p, 3p ... mark them out but not p it self
		if((max[i] = max[i]*p)){
			max[i] = 0;
			}
		}
		// look for the next i value which is not multiple of p 
		for(j = i*i; j <n; j+=i){
			max[j]=1;
			print_number(max[j]);
			printf("\n");
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
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
  
}

