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
    for (unsigned int j = 0; j < (256 / (8 * 8)); ++j) {
        for (unsigned int k = 0; k < 1; ++k) {
            R->X[j] = Q->X[j];
            R->Y[j] = Q->Y[j];
            R->Z[j] = Q->Z[j];
        }
    }
}
