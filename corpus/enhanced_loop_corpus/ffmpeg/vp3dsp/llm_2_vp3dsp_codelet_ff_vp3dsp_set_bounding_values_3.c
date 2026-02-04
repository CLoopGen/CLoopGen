#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed bounds
    int start = filter_limit;
    int end = (start + 128 < 256) ? start + 128 : 256; // prevent overflow
    int val = value;
    for (int i = 0; i < (end - start) && val > 0; i++) {
        int idx = start + i;
        bounding_values[idx] = val;
        bounding_values[2 * filter_limit - idx] = -val; // mirror around filter_limit
        val--;
    }
}
