#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
} P256_POINT_AFFINE;

extern P256_POINT *R;
extern  P256_POINT_AFFINE *Q;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2, unrolled by factor 2)
    for (i = 0; i < (256 / (8 * 8)); i += 2) {
        R->X[i]     = Q->X[i];
        R->Y[i]     = Q->Y[i];
        R->Z[i]     = 0;
        if (i + 1 < (256 / (8 * 8))) {
            R->X[i+1] = Q->X[i+1];
            R->Y[i+1] = Q->Y[i+1];
            R->Z[i+1] = 0;
        }
    }
}
