#include <stdio.h>
#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

static P256_POINT R_data;
static P256_POINT Q_data;

P256_POINT *R = &R_data;
P256_POINT *Q = &Q_data;
unsigned int i;

void init_vars() {
    for (int j = 0; j < 4; ++j) {
        Q->X[j] = 0x1000 + j;
        Q->Y[j] = 0x2000 + j;
        Q->Z[j] = 0x3000 + j;
    }
}