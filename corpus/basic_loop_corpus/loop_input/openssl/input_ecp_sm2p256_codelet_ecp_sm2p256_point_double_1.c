#include <stdio.h>
#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

static P256_POINT R_storage;
P256_POINT *R = &R_storage;
unsigned int i;

void init_vars() {
    for (int j = 0; j < 4; ++j) {
        R->X[j] = 0UL;
        R->Y[j] = 0UL;
        R->Z[j] = 0UL;
    }
}