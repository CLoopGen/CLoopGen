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
    int l, offset;
    for (l = 0; l < in_channels * 2; l += 2) {
        offset = l * buffer_length;
        buffer[l]     = ringbuffer + offset;
        if (l + 1 < in_channels) {
            buffer[l + 1] = ringbuffer + offset + buffer_length;
        }
    }
}
