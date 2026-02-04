#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies entirely by unrolling and reordering
    // Also remove masking computation redundancy via precomputed shifts
    int shift1_0 = 1 << 7; int shift1_1 = 1 << 6; int shift1_2 = 1 << 5; int shift1_3 = 1 << 4;
    int shift2_0 = 1 << 3; int shift2_1 = 1 << 2; int shift2_2 = 1 << 1; int shift2_3 = 1 << 0;

    if (mask & shift1_0) dst[0] = color;
    if (mask & shift2_0) dst[width + 0] = color;

    if (mask & shift1_1) dst[1] = color;
    if (mask & shift2_1) dst[width + 1] = color;

    if (mask & shift1_2) dst[2] = color;
    if (mask & shift2_2) dst[width + 2] = color;

    if (mask & shift1_3) dst[3] = color;
    if (mask & shift2_3) dst[width + 3] = color;
}
