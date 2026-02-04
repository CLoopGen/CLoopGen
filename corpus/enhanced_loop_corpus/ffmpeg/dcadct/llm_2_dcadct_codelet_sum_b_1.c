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
    int *in = input + 2;
    int *out = output + 1;
    int n = (len - 1);
    for (i = 0; i < n; i++) {
        out[i] = in[2*i] + in[2*i - 1];
    }
}
