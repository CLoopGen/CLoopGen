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

static P256_POINT R_data;
static P256_POINT_AFFINE Q_data;
P256_POINT *R = &R_data;
P256_POINT_AFFINE *Q = &Q_data;
unsigned int i;

void init_vars() {
    for (int j = 0; j < 4; ++j) {
        Q->X[j] = j + 1UL;
        Q->Y[j] = j + 5UL;
    }
}