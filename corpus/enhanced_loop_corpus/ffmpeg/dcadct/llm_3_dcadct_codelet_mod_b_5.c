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
    // Variant 2: Strided memory access on output with indirect indexing on input
    // Use a strided pattern on output (write every second element) and
    // indirect addressing via an index array for input accesses.
    int indices[] = {7, 6, 5, 4, 3, 2, 1, 0}; // indirect mapping for k
    int stride = 2;
    for (i = 0; i < 8; i++) {
        int actual_i = 8 + i * stride; // strided write into output
        int k_val = indices[i];
        output[actual_i] = input[k_val] - input[8 + k_val];
    }
}
