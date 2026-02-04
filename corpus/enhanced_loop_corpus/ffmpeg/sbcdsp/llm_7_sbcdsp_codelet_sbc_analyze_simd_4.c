#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *out;
extern unsigned int subbands;
extern int32_t t1[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (subbands > 0) {
        out[0] = t1[0] >> (15 - 15);
        for (i = 1; i < subbands; i++) {
            out[i] = t1[i] >> (15 - 15) + out[i-1];
        }
    }
}
