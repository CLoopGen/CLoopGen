#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        block[i] *= qmat[i];
        if (i + 1 < 64) {
            block[i + 1] *= qmat[i + 1];
        }
    }
}
