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
    for (n = 0; n < limit; n++) {
        double val;
        if (bit_depth == 8)
            val = (double)(buf[n] << 1);
        else
            val = (double)(((int32_t *)buf)[n] >> 1);
        ind[n] = val * val + 0.5 * val;
    }
}
