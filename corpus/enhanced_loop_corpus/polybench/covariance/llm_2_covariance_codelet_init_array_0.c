#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access - access every 4th element in row-major order, then fill in the gaps
    // This changes spatial locality and increases stride in the inner loop.
    int stride = 4;
    for (int s = 0; s < stride; s++) {
        for (i = 0; i < 1400; i++) {
            for (j = s; j < 1200; j += stride) {
                data[i][j] = ((double)i * j) / 1200;
            }
        }
    }
}
