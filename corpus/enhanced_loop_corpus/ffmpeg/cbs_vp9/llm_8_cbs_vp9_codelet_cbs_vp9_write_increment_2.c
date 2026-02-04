#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t range_min;
extern uint32_t value;
extern int len;
extern char bits[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (tripled effective operations)
    // Unroll by factor of 3 to increase arithmetic and comparison density
    int limit = len - (len % 3);
    for (i = 0; i < limit; i += 3) {
        if (range_min + i == value)
            bits[i] = '0';
        else
            bits[i] = '1';

        if (range_min + i + 1 == value)
            bits[i+1] = '0';
        else
            bits[i+1] = '1';

        if (range_min + i + 2 == value)
            bits[i+2] = '0';
        else
            bits[i+2] = '1';
    }
    // Handle remaining iterations
    for (; i < len; i++) {
        if (range_min + i == value)
            bits[i] = '0';
        else
            bits[i] = '1';
    }
}
