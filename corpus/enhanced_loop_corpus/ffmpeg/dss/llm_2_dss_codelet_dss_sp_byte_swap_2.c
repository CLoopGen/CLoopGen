#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to simulate sequential pattern
    // Original strided access (stride of 2) is transformed into consecutive writes by processing two elements at a time
    int n = 42 - 2;
    for (i = 0; i < n; i += 4) {
        if (i + 0 < n) dst[i + 0] = src[i + 4 + 0];
        if (i + 2 < n) dst[i + 2] = src[i + 4 + 2];
    }
}
