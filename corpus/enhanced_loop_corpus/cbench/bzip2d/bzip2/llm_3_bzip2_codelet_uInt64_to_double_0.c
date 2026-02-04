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



void loop() {
    // Variant 2: Indirect memory access using a fixed index mapping (bit-reversed order)
    const int indices[8] = {0, 4, 2, 6, 1, 5, 3, 7}; // Bit-reversal permutation for 3-bit indices
    sum = 0.0;
    base = 1.0;
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        sum += base * (double)(n->b[idx]);
        base *= 256.0;
    }
}
