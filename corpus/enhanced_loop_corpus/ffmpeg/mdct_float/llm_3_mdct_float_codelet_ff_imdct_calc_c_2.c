#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Pointer-based) Memory Access Pattern
    // Use pointers to traverse the output array indirectly
    // Base pointers are set to key positions and updated via pointer arithmetic
    FFTSample *out = output;
    FFTSample *mid_out = output + n2;
    FFTSample *end_out = output + n;

    for (k = 0; k < n4; k++) {
        // Access using computed offsets through pointers
        *(out + k) = -(*(mid_out - k - 1));
        *(end_out - k - 1) = *(mid_out + k);
    }
}
