#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        data[2 * (127 - i)] = 0.;         // Reverse access order: introduces WAW independence across iterations
        data[2 * (127 - i) + 1] = 0.;     // Eliminates loop-carried dependency by accessing decreasing indices
    }
}
