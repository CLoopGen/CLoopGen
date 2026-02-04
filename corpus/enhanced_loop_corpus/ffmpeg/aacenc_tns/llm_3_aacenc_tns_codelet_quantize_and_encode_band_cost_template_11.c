#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;
extern int j;
extern  int dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride over the output array
    int stride = 4; // Example stride, chosen to be realistic and within bounds for typical dim
    int limit = size - (size % stride); // Ensure we don't overflow
    for (i = 0; i < limit; i++) {
        for (j = 0; j < dim && (i + j * stride) < size; j++) {
            out[i + j * stride] = 0.F;
        }
    }
}
