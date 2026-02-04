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
    unsigned long temp_X[4] = {0};
    unsigned long temp_Y[4] = {0};
    unsigned long temp_Z[4] = {0};

    for (i = 0; i < (256 / (8 * 8)); ++i) {
        temp_X[i] = Q->X[i];
        temp_Y[i] = Q->Y[i];
        temp_Z[i] = 0;
    }

    for (i = 0; i < (256 / (8 * 8)); ++i) {
        K.X[i] = temp_X[i];
        K.Y[i] = temp_Y[i];
        K.Z[i] = temp_Z[i];
    }
}
