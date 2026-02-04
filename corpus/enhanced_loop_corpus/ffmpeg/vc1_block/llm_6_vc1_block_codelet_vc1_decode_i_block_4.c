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
    int16_t temp[8] = {0};
    for (k = 1; k < 8; k++) {
        temp[k] = ac_val[k];
    }
    for (k = 1; k < 8; k++) {
        block[k << sh] += temp[k];
    }
}
