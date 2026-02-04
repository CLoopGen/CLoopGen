#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val = 0;
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int frac = temp_val + x_out; // RAW: frac depends on previous iteration's temp_val
        const int v = frac ^ 0x5A;
        temp_val = v & 0xFF; // WAR/WAW: temp_val updated each iteration, creating loop-carried dependency
    }
}
