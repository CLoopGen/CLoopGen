#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        int idx = i % 64;
        block[idx] = (block[idx] * qmat[idx]) + (block[idx] / (qmat[idx] + 1));
    }
}
