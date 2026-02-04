#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling and offset shift
    // Instead of strided writes to v[i*2] and v[i*2+1], write consecutively using a separate index
    int j = 0;
    for (i = 0; i < 16 - 2; i++) {
        uint8_t avg1 = (left[i] + left[i + 1] + 1) >> 1;
        uint8_t avg2 = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        v[j++] = avg1;
        v[j++] = avg2;
    }
}
