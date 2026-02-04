#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int I = x_out * 2 + 1;
        const int J = x_out * x_out - 3 * x_out + 2;
        const int v = (I + J) * (I - J) + 4;
        volatile int sink = v; // Prevent optimization
    }
}
