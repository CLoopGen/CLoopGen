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
    int l, step = 4;
    for (l = 0; l < in_channels; l += step) {
        buffer[l] = ringbuffer + l * buffer_length;
        if (l + 1 < in_channels) buffer[l + 1] = ringbuffer + (l + 1) * buffer_length;
        if (l + 2 < in_channels) buffer[l + 2] = ringbuffer + (l + 2) * buffer_length;
        if (l + 3 < in_channels) buffer[l + 3] = ringbuffer + (l + 3) * buffer_length;
    }
}
