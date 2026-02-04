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
    if (n_read > 0) {
        j = 0;
        dst[2 * j] = ringbuffer[wr];
        ringbuffer[wr] = 0.;
        wr = (wr + 1) & modulo;
        
        for (j = 1; j < n_read; j++) {
            dst[2 * j] = ringbuffer[wr];
            ringbuffer[wr] = 0.;
            wr = (wr + 1) & modulo;
        }
    }
}
