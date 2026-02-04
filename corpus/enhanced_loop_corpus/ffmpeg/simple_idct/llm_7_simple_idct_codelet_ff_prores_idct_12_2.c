#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev = block[0];
    for (i = 0; i < 64; i++) {
        int16_t current = block[i];
        block[i] = current * qmat[i] + prev;
        prev = current;
    }
}
