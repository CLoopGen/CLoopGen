#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (i = 0; i < np; i += stride)
    for (j = 0; j < np; j += stride)
        C4[i][j] = (double)(i * j % np) / np;  // Strided memory access with step size 2
}
