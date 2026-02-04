#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int sz;
extern int bit_depth;
extern double ind[1024];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = sz * sz;
    int i;
    if (bit_depth == 8) {
        for (i = 0; i < limit; i++) {
            ind[i] = buf[i];
        }
    } else {
        for (i = 0; i < limit; i++) {
            ind[i] = ((int32_t *)buf)[i];
        }
    }
}
