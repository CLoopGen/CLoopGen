#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write to chebmo with offset, reading v in reverse order
    for (i = 0; i < 13; i++) {
        chebmo[i + 14] = v[12 - i];
    }
}
