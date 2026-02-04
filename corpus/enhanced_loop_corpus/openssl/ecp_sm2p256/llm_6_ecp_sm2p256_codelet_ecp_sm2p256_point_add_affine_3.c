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
    unsigned int j;
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        j = (256 / (8 * 8)) - 1 - i;
        K.X[j] = Q->X[i];
        K.Y[j] = Q->Y[i];
        K.Z[j] = 0;
    }
}
