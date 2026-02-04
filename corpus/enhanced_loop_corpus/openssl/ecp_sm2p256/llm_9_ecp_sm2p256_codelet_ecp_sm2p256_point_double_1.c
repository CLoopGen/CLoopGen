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
    for (i = 0; i < (256 / (4 * 8)); ++i) {
        R->Z[i % 4] = R->X[i % 4] + R->Y[i % 4] ^ (1UL << i);
    }
}
