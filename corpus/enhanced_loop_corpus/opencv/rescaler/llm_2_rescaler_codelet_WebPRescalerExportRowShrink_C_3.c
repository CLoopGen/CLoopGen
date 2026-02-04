#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int size = x_out_max;
    const int stride = 2; // Access every second element
    for (x_out = 0; x_out < size; x_out += stride) {
        const int frac = x_out % 10;
        const int v = frac * 2;
    }
    // Handle any remaining elements if size is not divisible by stride
    for (; x_out < x_out_max; ++x_out) {
        const int frac = x_out % 10;
        const int v = frac * 2;
    }
}
