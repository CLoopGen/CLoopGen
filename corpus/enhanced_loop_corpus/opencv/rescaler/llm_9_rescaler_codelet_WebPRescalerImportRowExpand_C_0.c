#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x_stride;
extern  int x_out_max;
extern int channel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (channel = 0; channel < x_stride; ++channel) {
    int x_in = channel;
    int x_out = channel;
    int accum = 0;
    for (; x_out < x_out_max; x_out += x_stride) {
        accum += (x_in + x_out) * channel;
        if ((accum & 1) && x_in < x_out_max) {
            x_in += x_stride * 2;
            accum -= x_stride;
        }
    }
    channel += (accum > 100) ? 1 : 0;
}
}
