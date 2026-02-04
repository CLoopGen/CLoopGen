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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 1792; i += 2) {
        output[i] *= a * (1792 - i - 1) + b * i;
        if (i + 1 < 1792) {
            output[i + 1] *= a * (1792 - (i + 1) - 1) + b * (i + 1);
        }
    }
}
