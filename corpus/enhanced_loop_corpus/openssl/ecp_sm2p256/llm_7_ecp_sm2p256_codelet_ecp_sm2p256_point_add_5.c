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
    unsigned long temp_X[4], temp_Y[4], temp_Z[4];
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        temp_X[i] = Q->X[i];
        temp_Y[i] = Q->Y[i];
        temp_Z[i] = Q->Z[i];
    }
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        R->X[i] = temp_X[i];
        R->Y[i] = temp_Y[i];
        R->Z[i] = temp_Z[i];
    }
}
