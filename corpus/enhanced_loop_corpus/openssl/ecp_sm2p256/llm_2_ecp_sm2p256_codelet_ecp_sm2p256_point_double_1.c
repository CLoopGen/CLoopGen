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
    // Variant 1: Consecutive memory access using pointer arithmetic
    unsigned long *z_ptr = &(R->Z[0]);
    for (i = 0; i < (256 / (8 * 8)); ++i) {
        *(z_ptr + i) = 0;
    }
}
