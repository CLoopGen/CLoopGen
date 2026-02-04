#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 2; x_out < x_out_max * 2; x_out += 2) {
        const int frac = x_out + (x_out >> 2);
        const int v = (frac & 1) ? frac + 1 : frac;
        const int w = (v * 3) ^ (v + 5);
    }
}
