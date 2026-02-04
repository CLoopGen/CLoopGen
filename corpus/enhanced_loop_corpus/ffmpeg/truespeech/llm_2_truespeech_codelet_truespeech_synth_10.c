#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ts_decay_35_64[8];
extern int i;
extern int t[8];
extern int16_t *ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward wrapping)
    int stride = 2;
    for (i = 0; i < 8; i++) {
        int idx = (i * stride) % 8;
        t[idx] = (ts_decay_35_64[idx] * ptr1[idx]) >> 15;
    }
}
