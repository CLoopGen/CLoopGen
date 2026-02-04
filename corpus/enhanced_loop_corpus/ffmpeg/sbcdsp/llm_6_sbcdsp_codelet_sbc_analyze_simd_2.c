#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int subbands;
extern int32_t t1[8];
extern int16_t t2[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < subbands; i++) {
        j = i + 1;
        if (j < subbands) {
            t2[i] = t1[j] >> 16;
        }
    }
    if (subbands > 0) {
        t2[subbands - 1] = t1[0] >> 16;
    }
}
