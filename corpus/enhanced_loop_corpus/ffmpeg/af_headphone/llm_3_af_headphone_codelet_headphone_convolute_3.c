#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ringbuffer;
extern  int in_channels;
extern  int buffer_length;
extern float *buffer[64];
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    int idx;
    for (idx = 0; idx < in_channels * stride; idx += stride) {
        int channel = idx / stride;
        buffer[channel] = ringbuffer + (channel * buffer_length);
    }
}
