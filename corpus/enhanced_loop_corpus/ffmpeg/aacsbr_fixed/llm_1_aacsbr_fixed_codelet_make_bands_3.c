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
if (num_bands > 1) {
    for (int outer = 0; outer < 1; outer++) {
        for (k = 0; k < num_bands - 1; k++) {
            prod = (int)(((int64_t)prod * base + 4194304) >> 23);
            present = (prod + 4194304) >> 23;
            bands[k] = present - previous;
            previous = present;
        }
    }
}
}
