#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *input;
extern int *output;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    for (i = 16, k = 15; i < 32; i += 2, k -= 2) {
        output[i] = input[k] - input[16 + k];
        if (i + 1 < 32) {
            output[i + 1] = input[k - 1] - input[15 + k];
        }
    }
}
