#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern float v2;
extern int size;
extern int i;
extern float step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (write every 2nd element)
    for (i = 0; i < size; i += 2) {
        v2 += step;
        out[i] = v2;
        if (i + 1 < size) {
            v2 += step;
            out[i + 1] = v2;
        }
    }
}
