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
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        if (!(i & 1)) {
            R->X[i] = Q->X[i];
            R->Y[i] = Q->Y[i];
            R->Z[i] = Q->Z[i];
        } else {
            R->X[i] = 0;
            R->Y[i] = 0;
            R->Z[i] = 0;
        }
    }
}
