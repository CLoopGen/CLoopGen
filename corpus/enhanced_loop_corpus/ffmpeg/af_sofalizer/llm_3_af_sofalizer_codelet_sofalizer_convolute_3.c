#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ringbuffer;
extern  int in_channels;
extern  int buffer_length;
extern float *buffer[16];
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int l;
    for (l = 0; l < in_channels; l += 2) {
        if (l + 1 < in_channels) {
            buffer[l + 1] = ringbuffer + (l + 1) * buffer_length;
        }
        buffer[l] = ringbuffer + l * buffer_length;
    }
}
