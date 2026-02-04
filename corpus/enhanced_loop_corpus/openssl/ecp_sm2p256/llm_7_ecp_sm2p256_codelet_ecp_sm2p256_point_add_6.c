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
    if ((256 / (8 * 8)) > 0) {
        R->X[0] = P->X[0];
        R->Y[0] = P->Y[0];
        R->Z[0] = P->Z[0];
        for (i = 1; i < (256 / (8 * 8)); ++i) {
            R->X[i] = R->X[i-1] + (P->X[i] - P->X[i-1]);
            R->Y[i] = R->Y[i-1] + (P->Y[i] - P->Y[i-1]);
            R->Z[i] = R->Z[i-1] + (P->Z[i] - P->Z[i-1]);
        }
    }
}
