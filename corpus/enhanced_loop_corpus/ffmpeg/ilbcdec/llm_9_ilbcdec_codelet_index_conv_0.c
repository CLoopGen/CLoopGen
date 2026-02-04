#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (k = 4; k < 7; k += 2) {
    int16_t val = index[k];
    if (val >= 44 && val < 108) {
        index[k] = (val + 64) * 3;
    } else if (val >= 108 && val < 128) {
        index[k] = (val + 128) >> 1;
    }
}
}
