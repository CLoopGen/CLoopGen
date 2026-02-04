#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max && x_out < 100; ++x_out) {
        if (x_out % 2 == 0) {
            const int frac = x_out * 2;
            const int v = x_out + 1;
            (void)frac;
            (void)v;
        } else {
            const int frac = x_out * 3;
            const int v = x_out - 1;
            (void)frac;
            (void)v;
        }
    }
}
