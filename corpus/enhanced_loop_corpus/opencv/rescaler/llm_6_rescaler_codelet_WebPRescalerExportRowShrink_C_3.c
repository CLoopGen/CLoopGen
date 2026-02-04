#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int frac = x_out % 7;
        const int v = frac * 2 + 1;
        // Introduce a write-after-write dependency by conditionally updating a shared variable
        if (v > 10) {
            x_out_max = x_out + v / 10; // WAW: modifies loop bound based on current iteration
        }
    }
}
