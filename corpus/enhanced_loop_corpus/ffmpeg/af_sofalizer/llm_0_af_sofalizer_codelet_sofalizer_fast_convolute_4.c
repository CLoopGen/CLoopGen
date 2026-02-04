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
    int j_inner;
    for (j = 0; j < n_read; j++) {
        for (j_inner = 0; j_inner < mult; j_inner++) {
            if (j_inner == 0) {
                dst[mult * j + j_inner] = ringbuffer[wr];
                ringbuffer[wr] = 0.F;
                wr = (wr + 1) & modulo;
            } else {
                dst[mult * j + j_inner] = 0.F;
            }
        }
    }
}
