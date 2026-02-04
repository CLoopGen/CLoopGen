#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern  P256_POINT *P;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (256 / (8 * 8)) / 2; ++i) { // Decreased effective iterations by increasing work per iteration
        R->X[i]           = P->X[i];
        R->Y[i]           = P->Y[i];
        R->Z[i]           = P->Z[i];
        R->X[i + 4]       = P->X[i + 4];
        R->Y[i + 4]       = P->Y[i + 4];
        R->Z[i + 4]       = P->Z[i + 4];
    }
}
