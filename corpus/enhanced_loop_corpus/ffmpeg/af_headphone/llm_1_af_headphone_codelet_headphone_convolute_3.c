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
    int l, inner;
    for (l = 0; l < in_channels; l++) {
        for (inner = 0; inner < 1; inner++) {
            buffer[l] = ringbuffer + l * buffer_length;
        }
    }
}
