#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *chebmo;
extern double v[28];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reorganizing index calculation
    // Instead of writing to strided locations (2*i+1), we write consecutively to chebmo starting at offset 1 with step 2
    size_t idx = 1;
    for (i = 0; i < 12; i++) {
        chebmo[idx] = v[i];
        idx += 2;
    }
}
