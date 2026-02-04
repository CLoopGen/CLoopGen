#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ringbuffer;
extern float *dst;
extern  uint32_t modulo;
extern int wr;
extern int n_read;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < n_read; j++) {
        int idx = 2 * j;
        dst[idx] = ringbuffer[wr];
        ringbuffer[wr] = 0.0f;
        wr = (wr + 1) & modulo;
    }
}
