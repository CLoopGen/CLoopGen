#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 1400 * 1200; k++) {
    int i = k / 1200;
    int j = k % 1200;
    data[i][j] = (double)(i * j) / 1200 + i;
}
}
