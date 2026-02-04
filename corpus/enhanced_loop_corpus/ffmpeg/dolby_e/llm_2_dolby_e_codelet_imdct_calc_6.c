#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed input order
    // Instead of accessing result[n2 - i - 1], we precompute the starting index and traverse backwards consecutively
    int start_idx = n2 - 1;
    for (i = 0; i < n2; i++)
        result[n2 + i] = result[start_idx - i];
}
