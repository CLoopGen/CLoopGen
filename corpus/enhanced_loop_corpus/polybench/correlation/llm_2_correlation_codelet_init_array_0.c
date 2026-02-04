#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (column-major with stride)
    for (j = 0; j < 1200; j++)
        for (i = 0; i < 1400; i++)
            data[i][j] = (double)(i * j) / 1200 + i;
}
