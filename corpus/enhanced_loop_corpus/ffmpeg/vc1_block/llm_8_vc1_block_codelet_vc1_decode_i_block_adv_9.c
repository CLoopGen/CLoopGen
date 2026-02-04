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
    for (k = 1; k < 16; k++) {
        if (k < 8) {
            block[k << sh] += ac_val[k];
        } else {
            block[(k - 8) << sh] -= ac_val[k % 8];
        }
    }
}
