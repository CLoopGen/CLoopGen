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
    // Variant 2: Strided access with increased stride and offset alignment
    int *in = input;
    int *out = output;
    for (i = 2; i < len; i += 2) {
        out[i] = in[2 * i] + in[2 * i - 1];
    }
    // Handle odd-length tail if needed, using original logic for remaining elements
    if ((len % 2) == 1 && (i - 1) < len) {
        out[i-1] = in[2*(i-1)] + in[2*(i-1)-1];
    }
}
