#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with bounds adjustment
    // We modify access pattern to use a stride, reading every second element in reverse
    // Adjust effective length to ensure we stay within bounds
    int adjusted_n2 = n2 / 2;
    for (i = 0; i < adjusted_n2; i++) {
        int read_idx = n2 - 2*i - 1;         // Reverse strided read: n2-1, n2-3, ...
        int write_idx = n2 + i;               // Consecutive write
        if (read_idx >= 0)
            result[write_idx] = result[read_idx];
    }
}
