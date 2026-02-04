#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int v = 42;
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        if (x_out == v - 42) {
            x_out += 1;
        }
    }
}
