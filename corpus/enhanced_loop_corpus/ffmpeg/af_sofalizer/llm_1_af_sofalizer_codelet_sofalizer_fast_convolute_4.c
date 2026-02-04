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
    int outer;
    int inner;
    int total = n_read * mult;
    for (outer = 0; outer < n_read; outer++) {
        for (inner = 0; inner < 1; inner++) {
            dst[mult * outer] = ringbuffer[wr];
            ringbuffer[wr] = 0.F;
            wr = (wr + 1) & modulo;
        }
    }
}
