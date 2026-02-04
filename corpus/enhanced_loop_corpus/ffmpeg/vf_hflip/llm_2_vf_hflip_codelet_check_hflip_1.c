#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int step;
extern int i;
extern int step_array[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, forward and backward fill)
    for (i = 0; i < 4; i += 2) {
        step_array[i] = step;
        if (i + 1 < 4) {
            step_array[i + 1] = step;
        }
    }
}
