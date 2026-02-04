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
    for (l = 0; l < in_channels && ringbuffer != NULL; l++) {
        buffer[l] = ringbuffer + l * buffer_length;
    }
}
