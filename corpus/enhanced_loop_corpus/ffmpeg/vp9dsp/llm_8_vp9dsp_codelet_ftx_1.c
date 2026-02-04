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
    for (n = 0; n < sz * sz; n += 2) {
        if (bit_depth == 8) {
            ind[n] = buf[n];
            if (n + 1 < sz * sz)
                ind[n + 1] = buf[n + 1] * 1.5;
        } else {
            int32_t *buf32 = (int32_t *)buf;
            ind[n] = buf32[n] + 10;
            if (n + 1 < sz * sz)
                ind[n + 1] = buf32[n + 1] - 5;
        }
    }
}
