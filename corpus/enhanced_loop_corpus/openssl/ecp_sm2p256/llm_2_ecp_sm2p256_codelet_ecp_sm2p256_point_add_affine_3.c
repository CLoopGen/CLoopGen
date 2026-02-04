#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
} P256_POINT_AFFINE;

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern  P256_POINT_AFFINE *Q;
extern unsigned int i;
extern P256_POINT K;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (simulating non-unit stride pattern)
    // Access only even indices within bounds, unrolling behavior to demonstrate strided access
    for (i = 0; i < (256 / (8 * 8)); i += 2) {
        if (i < (256 / (8 * 8))) {
            K.X[i] = Q->X[i];
            K.Y[i] = Q->Y[i];
            K.Z[i] = 0;
        }
        if ((i + 1) < (256 / (8 * 8))) {
            K.X[i + 1] = Q->X[i + 1];
            K.Y[i + 1] = Q->Y[i + 1];
            K.Z[i + 1] = 0;
        }
    }
}
