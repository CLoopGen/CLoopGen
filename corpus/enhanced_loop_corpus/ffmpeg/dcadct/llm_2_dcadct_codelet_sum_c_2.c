#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *input;
extern int *output;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    int *in = input;
    int *out = output;
    for (i = 0; i < len; i++) {
        out[i] = in[i]; // Changed to consecutive access: input[i] instead of input[2*i]
    }
}
