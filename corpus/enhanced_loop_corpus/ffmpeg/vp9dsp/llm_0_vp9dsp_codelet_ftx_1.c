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
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            int idx = i * sz + j;
            if (bit_depth == 8)
                ind[idx] = buf[idx];
            else
                ind[idx] = ((int32_t *)buf)[idx];
        }
    }
}
