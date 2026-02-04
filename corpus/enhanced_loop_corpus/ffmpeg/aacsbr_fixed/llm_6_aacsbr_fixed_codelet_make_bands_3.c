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
    int temp_previous = previous;
    for (k = 0; k < num_bands - 1; k++) {
        int64_t temp_prod = ((int64_t)prod * base + 4194304) >> 23;
        int temp_present = (temp_prod + 4194304) >> 23;
        bands[k] = temp_present - temp_previous;
        temp_previous = temp_present;
    }
}
