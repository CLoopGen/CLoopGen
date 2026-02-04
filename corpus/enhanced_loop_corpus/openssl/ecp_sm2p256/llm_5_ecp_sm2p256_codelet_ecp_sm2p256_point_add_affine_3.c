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
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        K.Z[i] = 0;
        if (Q->X[i] != 0 || Q->Y[i] != 0) {
            K.X[i] = Q->X[i];
            K.Y[i] = Q->Y[i];
        } else {
            K.X[i] = 1;
            K.Y[i] = 1;
        }
    }
}
