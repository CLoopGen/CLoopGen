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
    // Variant 2: Reverse Order Access (consecutive but in descending order)
    for (i = (256 / (8 * 8)) - 1; i != (unsigned int)-1; --i) {
        R->X[i] = Q->X[i];
        R->Y[i] = Q->Y[i];
        R->Z[i] = 0;
    }
}
