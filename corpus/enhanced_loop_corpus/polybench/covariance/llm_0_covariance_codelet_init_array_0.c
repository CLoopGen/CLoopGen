#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1400 * 1200; i++) {
    int row = i / 1200;
    int col = i % 1200;
    data[row][col] = ((double)row * col) / 1200;
}
}
