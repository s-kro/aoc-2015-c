#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Advent of Code Day 3 Part 1 */

int main() {
  FILE *fptr;
  char c; // instruction from drunk elf at North Pole
    
  if ((fptr = fopen("./aoc_2015-3.dat", "r")) == NULL) {
    return 1;
  }
  
  int i;
  int x_min = 0, x_max = 0, y_min = 0, y_max = 0;
  int **houses;
  int houses_visited = 1;

  for (i = 0; i < 2; i++) { // first run through is just to get the 
    rewind(fptr); // extents of the grid of houses
    if (i == 1) {
      int j;
      houses = (int**)malloc(sizeof(int*) * (x_max - x_min)); 
      for (j = x_min; j <= x_max; j++) {
	houses[j - x_min] = (int*)calloc((y_max - y_min), sizeof(int));
      }
    }

    int x = 0, y = 0; // Santa's position
    do {
      c = fgetc(fptr);
      switch (c) {
      case '^': // up
	x++;
	if (i == 0 && x > x_max) {
	  x_max = x; } 
	break;
      case 'v': // down
	x--;
	if (i == 0 && x < x_min) {
	  x_min = x; }
	break;
      case '>': // right
	y++; 
	if (i == 0 && y > y_max) {
	  y_max = y; }
	break;
      case '<': // left
	y--;
	if (i == 0 && y < y_min) {
	  y_min = y; }
	break;
      }
      if (i == 1 && ++houses[x - x_min][y - y_min] == 1) {
	houses_visited++; } // only count first visits
    
    } while (c != EOF);
  }
  printf("Total houses visited %d \n", houses_visited);
  
  fclose(fptr);
  return 0;
}

