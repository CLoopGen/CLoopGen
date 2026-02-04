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
    int stride = 2;
    for (n = 0; n < sz * sz; n += stride) {
        if (bit_depth == 8)
            ind[n] = buf[n];
        else
            ind[n] = ((int32_t *)buf)[n];
        // Handle potential out-of-bounds on last iteration
        if (n + 1 < sz * sz) {
            int next = n + 1;
            if (bit_depth == 8)
                ind[next] = buf[next];
            else
                ind[next] = ((int32_t *)buf)[next];
        }
    }
}
