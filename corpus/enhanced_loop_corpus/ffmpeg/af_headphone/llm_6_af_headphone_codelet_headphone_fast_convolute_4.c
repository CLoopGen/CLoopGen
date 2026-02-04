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
    float temp;
    for (j = 0; j < n_read; j++) {
        temp = ringbuffer[wr];
        dst[2 * j] = temp;
        ringbuffer[wr] = 0.;
        wr = (wr + 1) & modulo;
    }
}
