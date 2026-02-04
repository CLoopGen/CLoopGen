#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Stride
    // Change access pattern to stride of 1 but step through the array with larger logical blocks
    // Effectively process every 4th element in each pass (loop unroll across stride)
    for (i = 0; i < 4 * len4; i += 4) {
        y[i]     += alpha * x[i];
        y[i + 1] += alpha * x[i + 1];
        y[i + 2] += alpha * x[i + 2];
        y[i + 3] += alpha * x[i + 3];
    }
}
