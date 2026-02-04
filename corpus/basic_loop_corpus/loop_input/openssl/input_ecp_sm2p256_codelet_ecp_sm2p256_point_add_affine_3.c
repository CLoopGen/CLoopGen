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

P256_POINT_AFFINE *Q;
unsigned int i;
P256_POINT K;

void init_vars() {
    static P256_POINT_AFFINE Q_storage;
    Q = &Q_storage;

    for (int j = 0; j < 4; ++j) {
        Q->X[j] = 0x12345678UL + j;
        Q->Y[j] = 0x87654321UL + j;
    }

    for (int j = 0; j < 4; ++j) {
        K.X[j] = 0;
        K.Y[j] = 0;
        K.Z[j] = 0;
    }
}