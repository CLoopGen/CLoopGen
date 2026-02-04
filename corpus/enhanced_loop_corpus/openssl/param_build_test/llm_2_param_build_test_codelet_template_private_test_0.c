#include <stdio.h>

#include <inttypes.h>

extern int *data1;
extern int j;
extern  int data1_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then fill odd indices in second pass)
    int stride = 2;
    // First pass: even indices
    for (j = 0; j < data1_num; j += stride)
        data1[j] = -16 * j;
    // Second pass: odd indices if within bounds
    for (j = 1; j < data1_num; j += stride)
        data1[j] = -16 * j;
}
