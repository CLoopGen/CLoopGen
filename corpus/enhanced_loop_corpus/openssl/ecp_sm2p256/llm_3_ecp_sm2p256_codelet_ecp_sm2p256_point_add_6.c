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
    // Variant 2: Strided access - process one array at a time with stride of 4 between elements in each array
    for (i = 0; i < 4; ++i) {
        R->X[i] = P->X[i];
    }
    for (i = 0; i < 4; ++i) {
        R->Y[i] = P->Y[i];
    }
    for (i = 0; i < 4; ++i) {
        R->Z[i] = P->Z[i];
    }
}
