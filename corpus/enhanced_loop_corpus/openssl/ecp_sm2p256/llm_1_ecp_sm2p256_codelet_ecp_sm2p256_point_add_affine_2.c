#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
} P256_POINT_AFFINE;

extern P256_POINT *R;
extern  P256_POINT_AFFINE *Q;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (256 / (8 * 8)) / 2; ++i) {
        // Unrolled version with two iterations per loop cycle
        R->X[i * 2] = Q->X[i * 2];
        R->Y[i * 2] = Q->Y[i * 2];
        R->Z[i * 2] = 0;

        R->X[i * 2 + 1] = Q->X[i * 2 + 1];
        R->Y[i * 2 + 1] = Q->Y[i * 2 + 1];
        R->Z[i * 2 + 1] = 0;
    }
    // Handle any remaining element if the original count was odd (though here it's fixed at 4)
    if ((256 / (8 * 8)) % 2 != 0) {
        int last = (256 / (8 * 8)) - 1;
        R->X[last] = Q->X[last];
        R->Y[last] = Q->Y[last];
        R->Z[last] = 0;
    }
}
