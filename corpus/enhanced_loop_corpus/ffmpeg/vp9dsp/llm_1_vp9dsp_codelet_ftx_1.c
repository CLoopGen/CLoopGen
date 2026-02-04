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
    for (int k = 0; k < sz; k++) {
        int base = k * sz;
        for (int l = 0; l < sz; l++) {
            int idx = base + l;
            if (bit_depth == 8)
                ind[idx] = buf[idx];
            else
                ind[idx] = ((int32_t *)buf)[idx];
        }
    }
}
