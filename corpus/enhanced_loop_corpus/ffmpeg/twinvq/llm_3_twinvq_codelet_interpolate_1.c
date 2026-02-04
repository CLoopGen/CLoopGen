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
    // Variant 2: Reverse consecutive memory access (write in reverse order)
    for (i = size - 1; i >= 0; i--) {
        out[i] = v2;
        v2 += step;
    }
}
