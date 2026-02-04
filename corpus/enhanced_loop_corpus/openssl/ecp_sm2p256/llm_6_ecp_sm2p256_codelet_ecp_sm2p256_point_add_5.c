#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern  P256_POINT *Q;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        j = (256 / (8 * 8)) - 1 - i;
        R->X[j] = Q->X[i];
        R->Y[j] = Q->Y[i];
        R->Z[j] = Q->Z[i];
    }
}
