#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = block[i] >> 3;
    }
    for (i = 0; i < 64; i++) {
        block[i] = temp[i];
    }
}
