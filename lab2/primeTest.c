#include<stdio.h>
#include<stdlib.h>
#define COLUMNS 6
int main(){
	for(int i =0; i <= 105; i++){
		if(is_prime(i) !=0)
		
	}
	print_number(is_prime(i));
}

int is_prime(int n){
	int p;  
	for(p = 2; p < n; p++){
    	if(n % p ==0 && p != n)
        	return 0;  
	}
	return p;
}
void print_number(int n){
	int i;
	for(i = 0; i <= n; i++){
		if(i % COLUMNS == 0)
		
		printf("\n");
		printf("%d\t",i);
		
		printf("\n");
	}
}
