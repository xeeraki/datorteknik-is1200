// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COLUMNS 6
void print_number(int n){
	 printf("%10d ", n);

}

void print_sieves_heap(int n)
{
 int c = 0;

 bool *buf = malloc(sizeof(bool)*n);
 // start of Sieve_of_Eratosthenes algorithm
 for(int i = 0; i <=n; i++){
       buf[i] = true;
					       }
  buf[0] = false;
  buf[1] = false;

  for(int i = 2; i <=n; i++)
  {
	  if(buf[i] == true)
	  {
		  for(int j = 2; i * j <=n; j++){
		         buf[i * j] = false;   // set all index numbers that are divisable by numbers other than themselves and 1 to false
                                        }
      }
  }

  // for loop that prints the prime numbers in given formatting up to n
   for(int a = 2; a <= n; a++)
   {
	   if(buf[a] == true)
	   {
		   print_number(a);
		   c++;
		   if(c==COLUMNS)
		   {
			 printf("\n");
			 c = 0;
		   }
	   }
   }
   free(buf);

}
int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves_heap(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

