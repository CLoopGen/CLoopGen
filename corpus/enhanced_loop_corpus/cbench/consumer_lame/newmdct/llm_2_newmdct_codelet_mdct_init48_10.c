#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Instead of accessing consecutive elements, we skip every other element
    int stride = 2;
    for (k = 0; k < 7; k++) {
        wr[k * stride] = wp[k * stride] / w;
    }
}
