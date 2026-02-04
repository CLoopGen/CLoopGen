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
        unsigned long temp_x = P->X[i];
        unsigned long temp_y = P->Y[i];
        unsigned long temp_z = P->Z[i];
        R->X[i] = temp_x;
        R->Y[i] = temp_y;
        R->Z[i] = temp_z;
    }
}
