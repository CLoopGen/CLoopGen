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
    for (i = 0; i < (256 / (8 * 8)) * 2; ++i) {
        unsigned int idx = i % 4;
        R->X[idx] = (Q->X[idx] + i);
        R->Y[idx] = (Q->Y[idx] + i);
        R->Z[idx] = (i > 3) ? 1 : 0;
    }
}
