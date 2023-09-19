#include <stdio.h>

int main() {
  FILE *fptr;
  char c;
  int fl = 0;
  int t = 0;
    
  if ((fptr = fopen("./aoc_2015-1.dat","r")) == NULL) {
    return 1;
  }
  
  do {
    c = fgetc(fptr);
    t++;
    if (c == '(') {
      fl++; 
    } else if (c == ')') {
      fl--;
      if (fl == -1) {
	printf("First basement level %d \n", t);
	break;
      }
    }
       
  } while (c != EOF);
  
  fclose(fptr);
  return 0;
}
