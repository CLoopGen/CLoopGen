#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float best_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (accessing array from end to start)
    for (i = 39; i >= 0; i--) {
        data[i] -= best_gain * work[i];
    }
}
