#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int16_t *ac_val;
extern int k;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_offset = 1 << sh;
    for (k = 1; k < 8; k++) {
        int16_t curr_offset = k << sh;
        block[curr_offset] += ac_val[k] + block[prev_offset];
        prev_offset = curr_offset;
    }
}
