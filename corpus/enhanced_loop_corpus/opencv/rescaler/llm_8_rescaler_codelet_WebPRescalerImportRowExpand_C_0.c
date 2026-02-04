#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x_stride;
extern  int x_out_max;
extern int channel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (channel = 0; channel < x_stride * 2; channel += 2) {
    int x_in = channel;
    int x_out = channel;
    int accum = x_in * x_out;
    for (int step = 0; step < x_out_max - channel; step++) {
        x_out += x_stride;
        if (x_out >= x_out_max) break;
        accum += x_in * x_stride - step;
        x_in += (accum < 0) ? x_stride : 0;
    }
}
}
