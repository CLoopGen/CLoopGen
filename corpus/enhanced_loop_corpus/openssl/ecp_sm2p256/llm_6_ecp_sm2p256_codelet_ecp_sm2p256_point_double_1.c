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
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        R->Z[i] = R->X[i] & 0x0; // Introduce RAW dependency: use X[i] to compute Z[i], though result is still 0
    }
}
