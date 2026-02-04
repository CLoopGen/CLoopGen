#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_pixels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < num_pixels; ++i) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // The value of temp is updated each iteration and used in the next, creating a loop-carried flow (RAW) dependency.
}
