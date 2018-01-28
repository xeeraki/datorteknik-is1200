#include <stdio.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
int n1[20];   // make space for 80 byte
int n2[20];   // make space for 80 byte
int* list1 = n1;
int* list2 = n2;
int count;

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));

}

void copycodes(char*text, int*list, int c)
{
            while(*text!=0)
            {
				  *list = (int)*text; //convert characther to int from text and place it in list
				  text++; //increment pointer to next char
				  list++; //increment pointer to next position for int
				  c++;    //increase count
			}
			count = c;


}
void work()
{
	copycodes(text1,list1,count);
	copycodes(text2,list2,count);
}


int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
