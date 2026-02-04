#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access - traverse column-major order (transpose the iteration)
    for (l = 0; l < 20; ++l)
        for (k = 0; k < (6 + 1); ++k)
            statistics[k][l] = 0;
}
