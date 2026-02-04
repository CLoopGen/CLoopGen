#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int I = x_out;
        for (int k = 0; k < 10; ++k) {
            const int J = k;
            const int v = I + J;
        }
    }
}
