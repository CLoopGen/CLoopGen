#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int I = x_out * 2;
        const int J = x_out + 1;
        const int v = (I > J) ? I : J;

        if (v % 3 == 0) {
            continue;
        }
        x_out += (x_out & 1); // Skip even indices by incrementing further
    }
}
