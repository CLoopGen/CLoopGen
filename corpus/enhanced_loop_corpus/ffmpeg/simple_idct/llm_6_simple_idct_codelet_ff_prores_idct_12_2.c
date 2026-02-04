#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = block[i] * qmat[i];
    }
    for (i = 0; i < 64; i++) {
        block[i] = temp[i];
    }
}
