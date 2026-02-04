#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern union av_intfloat32 *zi;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Original strided access is transformed into consecutive writes by reordering
    // and precomputing indices to improve spatial locality.
    uint32_t temp[128]; // Local buffer for consecutive stores
    int idx = 0;
    for (k = 1; k < 31; k += 2) {
        temp[idx++] = zi[64 - k].i ^ (1U << 31);
        temp[idx++] = zi[k + 1].i;
        temp[idx++] = zi[63 - k].i ^ (1U << 31);
        temp[idx++] = zi[k + 2].i;
    }
    // Flush temp buffer consecutively into target region starting at zi[64]
    for (int j = 0; j < idx; j++) {
        zi[64 + j].i = temp[j];
    }
}
