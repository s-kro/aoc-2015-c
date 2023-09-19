#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Advent of Code Day 2 Part 2 */

void swap(int*, int*);
void array_sort(int[], int);

int main() {
  FILE *fptr;
  char c;
  char s[] = " ";
  int box[] = {0, 0, 0}; // {l, w, h}
  int ribbon = 0;
    
  if ((fptr = fopen("./aoc_2015-2.dat", "r")) == NULL) {
    return 1;
  }

  int i = 0; // track which side of the box we're working on
  char num[4] = ""; // a string to read in our numbers
  do {
    c = fgetc(fptr);
    if (c == 'x' || c == '\n') { // end of number
      box[i] = atoi(num);
      memset(num, 0, sizeof(num));
      if (c == 'x') { // first two sides
	i++;
      }
      else if (c == '\n') { // .. and the last side of box
	array_sort(box, 3);
	ribbon += 2 * (box[0] + box[1]) +  box[0] * box[1] * box[2];
	i = 0;
      }
    } else {
      s[0] = c; // a cheat to convert our char to a string
      strcat(num, s); // so we can cat it
    }
  } while (c != EOF);
  
  printf("Total ribbon %d \n", ribbon);
  fclose(fptr);
  return 0;
}

void swap(int* xp, int* yp)
{ // Ye ol' swap-a-roo
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void array_sort(int arr[], int n)
{ // Sort an array lowest to highest elements
  int i, j, min_idx;
  
  for (i = 0; i < n - 1; i++) { // Track the unsorted boundary 
    min_idx = i;     // Find the minimum element in the
    for (j = i + 1; j < n; j++) { // unsorted part of
      if (arr[j] < arr[min_idx]) { // the array
	min_idx = j;
      }
    } // new minimum trades with the boundary element
    swap(&arr[min_idx], &arr[i]);
  }
}
