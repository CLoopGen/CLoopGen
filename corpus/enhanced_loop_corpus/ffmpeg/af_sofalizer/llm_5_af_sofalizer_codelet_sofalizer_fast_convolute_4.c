#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ringbuffer;
extern  int mult;
extern float *dst;
extern  uint32_t modulo;
extern int wr;
extern int n_read;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < n_read; j++) {
        float temp = ringbuffer[wr];
        dst[mult * j] = temp;
        if (temp != 0.F) {
            ringbuffer[wr] = 0.F;
        }
        wr = (wr + 1) & modulo;
    }
}
