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
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        R->X[i] = P->X[i] + 1;
        R->Y[i] = P->Y[i] + 2;
        R->Z[i] = P->Z[i] + 3;
    }
}
