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
    // Variant 1: Strided memory access (access every second element, forward and backward pass to cover all)
    sum = 0.0;
    base = 1.0;
    for (i = 0; i < 8; i += 2) {
        sum += base * (double)(n->b[i]);
        base *= 256.0;
    }
    for (i = 1; i < 8; i += 2) {
        sum += base * (double)(n->b[i]);
        base *= 256.0;
    }
}
