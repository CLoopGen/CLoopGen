#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *bands;
extern int num_bands;
extern int k;
extern int previous;
extern int present;
extern int base;
extern int prod;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < (num_bands - 1) / 2; k++) {
        prod = (int)(((int64_t)prod * base + 8388608) >> 24);
        present = (prod + 2097152) >> 22;
        bands[k] = (present - previous) << 1;
        previous = present;
    }
}
