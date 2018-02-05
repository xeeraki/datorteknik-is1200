#include<stdio.h>
#define COLUMNS 6

void printNumber(int n){
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
  	return 1;
 }
 
int main(void){
  	int count;
  	int i;
 	for(i = 0; i < 105; i++){
		if(is_prime(i)==1){
		count++;
		}
  	 }
 	printNumber(count);
}


