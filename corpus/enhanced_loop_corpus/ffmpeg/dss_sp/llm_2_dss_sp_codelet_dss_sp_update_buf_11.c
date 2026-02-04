#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *hist;
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with offset adjustment
    int32_t *vec_base = vector + 1; // Adjust base so we write to vector[1..72]
    for (i = 0; i < 72; i++)
        vec_base[i] = hist[i]; // Now accessing both arrays consecutively
}
