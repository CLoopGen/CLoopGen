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
    x_in += x_stride;
    for (; x_out < x_out_max; ) {
        x_out += x_stride;
        if (accum < 0) {
            x_in += x_stride;
        }
    }
}
}
