#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern int last;
extern  int originalLast;
extern int i;
extern int nextend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 (unrolled-like pattern)
    // Processes two elements per iteration with non-unit stride to increase cache variability.
    int step = 2;
    for (i = 0; i < nextend; i += step) {
        int adjusted_i = i;
        if (adjusted_i < nextend) {
            output[++last] = output[originalLast - 1 - adjusted_i];
        }
        adjusted_i++;
        if (adjusted_i < nextend) {
            output[++last] = output[originalLast - 1 - adjusted_i];
        }
    }
}
