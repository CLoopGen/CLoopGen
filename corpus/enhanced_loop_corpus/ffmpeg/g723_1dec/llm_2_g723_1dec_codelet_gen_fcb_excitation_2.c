#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int beta;
extern int lag;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with positive stride
    // Instead of sequential i++, we process every 2nd element in forward direction
    for (i = lag; i < 60; i += 2) {
        if (i - lag >= 0)
            vector[i] += beta * vector[i - lag] >> 15;
    }
    // Handle remaining index if 60 is odd and lag <= 59
    for (i = lag + 1; i < 60; i += 2) {
        if (i - lag >= 0)
            vector[i] += beta * vector[i - lag] >> 15;
    }
}
