#include <stdio.h>

int main() {
  FILE *fptr;
  char c;
  int fl = 0;
    
  if ((fptr = fopen("./aoc_2015-1.dat","r")) == NULL) {
    return 1;
  }
  
  do {
    c = fgetc(fptr);
    if (c == '(') {
      fl++; 
    } else if  (c == ')') {
      fl--;
    }
      
  } while (c != EOF);
  
  printf("%d \n", fl);
  fclose(fptr);
  return 0;
}
