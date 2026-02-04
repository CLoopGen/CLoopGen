#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *input;
extern int *output;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to improve spatial locality
    // Access pattern changed to load consecutive elements where possible
    int j;
    for (j = 0; j < len * 2; j += 2) {
        output[j / 2] = input[j] + input[j + 1];
    }
}
