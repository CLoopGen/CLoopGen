#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern AVInteger b;
extern int i;
extern int carry;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (forward and wrap-around)
    // Access pattern: 0, 2, 4, 6, 1, 3, 5, 7
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7};
    carry = (carry & 0xFFFF0000) >> 16; // Extract initial carry high bits
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        carry = (carry >> 16) + a.v[idx] - b.v[idx];
        a.v[idx] = carry;
    }
}
