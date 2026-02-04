#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float mantissa_tab1[17][4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering computations
    // Instead of accessing mantissa_tab1[i][1], then [i][2], then [i][3] for each i,
    // we separate the assignments into three consecutive loops, improving spatial locality
    // for each component across different i values.

    float *col1 = &mantissa_tab1[2][1];
    float *col2 = &mantissa_tab1[2][2];
    float *col3 = &mantissa_tab1[2][3];

    for (i = 2; i < 16; i++) {
        int shift_val = (1 << i) - 1;
        col1[i - 2] = 1.F / shift_val;
    }
    for (i = 2; i < 16; i++) {
        int shift_val = (1 << i) - 1;
        col2[i - 2] = 0.5F / shift_val;
    }
    for (i = 2; i < 16; i++) {
        int shift_val = (1 << i) - 1;
        col3[i - 2] = 0.25F / shift_val;
    }
}
