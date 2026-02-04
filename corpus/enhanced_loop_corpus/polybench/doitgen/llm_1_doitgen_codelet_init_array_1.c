#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < np * np; i++) {
    int row = i / np;
    int col = i % np;
    C4[row][col] = (double)(row * col % np) / np;
}
}
