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
    // Variant 2: Strided access - process one field at a time with stride of 4 between elements in each array
    for (i = 0; i < 4; ++i) {
        if (i < (256 / (8 * 8))) {
            R->X[i] = Q->X[3 - i];  // Reverse order access in X
            R->Y[i] = Q->Y[3 - i];  // Reverse order access in Y
            R->Z[i] = Q->Z[3 - i];  // Reverse order access in Z
        }
    }
}
