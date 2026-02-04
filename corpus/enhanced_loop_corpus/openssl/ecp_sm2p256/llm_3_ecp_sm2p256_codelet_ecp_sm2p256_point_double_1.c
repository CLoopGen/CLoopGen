#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 2 (unrolling effect)
    // Only write to even indices within the allowed range, effectively halving iterations
    for (i = 0; i < (256 / (8 * 8)); i += 2) {
        R->Z[i] = 0;
        if (i + 1 < (256 / (8 * 8))) {
            R->Z[i + 1] = 0;
        }
    }
}
