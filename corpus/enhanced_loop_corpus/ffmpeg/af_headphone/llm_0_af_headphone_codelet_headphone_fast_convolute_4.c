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
    int j_inner;
    for (j = 0; j < n_read; j++) {
        for (j_inner = 0; j_inner < 1; j_inner++) {
            dst[2 * j] = ringbuffer[wr];
            ringbuffer[wr] = 0.;
            wr = (wr + 1) & modulo;
        }
    }
}
