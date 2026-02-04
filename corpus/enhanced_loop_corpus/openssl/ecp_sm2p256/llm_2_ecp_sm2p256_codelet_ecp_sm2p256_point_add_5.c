#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern  P256_POINT *Q;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the structure access into a single loop over raw elements
    unsigned long *src = (unsigned long *)Q;
    unsigned long *dst = (unsigned long *)R;
    for (i = 0; i < (256 / (8 * 8)) * 3; ++i) {
        dst[i] = src[i];
    }
}
