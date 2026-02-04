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
    int i;
    for (i = 0; i < in_channels; i++) {
        buffer[i] = &ringbuffer[i * buffer_length];
    }
}
