#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 8; i += 2) {
        output[i] = input[i] + input[8 + i];
        if (i + 1 < 8) {
            output[i + 1] = input[i + 1] + input[8 + (i + 1)];
        }
    }
}
