#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

extern UInt64 *n;
extern Int32 i;
extern double base;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, then wrap around for odd indices)
    sum = 0.0;
    base = 1.0;
    Int32 stride = 2;
    Int32 j;
    // First pass: even indices with stride
    for (j = 0; j < 8; j += stride) {
        if (j < 8) {
            sum += base * (double)(n->b[j]);
            base *= 256.0;
        }
    }
    // Second pass: odd indices to cover all elements
    for (j = 1; j < 8; j += stride) {
        sum += base * (double)(n->b[j]);
        base *= 256.0;
    }
}
