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
    // Variant 2: Reduced arithmetic operations using precomputed offset difference
    // Instead of computing (range_min + i) each time, compute delta once
    uint32_t base = value - range_min;
    for (i = 0; i < len; i++) {
        if (i == base)
            bits[i] = '0';
        else
            bits[i] = '1';
    }
}
