#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int frac = (x_out > 10) ? x_out - 5 : x_out + 5;
        const int v = frac * 2;
        if (v <= 20) {
            break;
        }
    }
}
