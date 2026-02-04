#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned long X[4];
    unsigned long Y[4];
    unsigned long Z[4];
} P256_POINT;

extern P256_POINT *R;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (j = 0; j < (256 / (8 * 8)); ++j) {
        R->Z[j] = 0;
        R->X[j] = R->Z[j] + 1; // Introduce RAW dependency: Z[j] written before used in X[j]
    }
}
