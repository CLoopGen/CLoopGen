#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern float a;
extern float b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = 1791; i >= 0; i--) {
        output[i] *= a * (1792 - i - 1) + b * i;
    }
}
