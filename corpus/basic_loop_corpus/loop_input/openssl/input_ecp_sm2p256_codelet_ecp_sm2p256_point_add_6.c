#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

static P256_POINT P_data;
static P256_POINT R_data;
P256_POINT *R = &R_data;
P256_POINT *P = &P_data;
unsigned int i;

void init_vars() {
    for (int j = 0; j < 4; ++j) {
        P->X[j] = 0x10000000UL + (j * 7);
        P->Y[j] = 0x20000000UL + (j * 11);
        P->Z[j] = 0x30000000UL + (j * 13);
    }
    memset(&R_data, 0, sizeof(R_data));
}