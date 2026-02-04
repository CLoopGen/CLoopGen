#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive linear memory access using pointer arithmetic
    int *p = &statistics[0][0];
    int total_elements = (6 + 1) * 20;
    for (k = 0; k < total_elements; ++k)
        p[k] = 0;
}
