#include <stdio.h>

#include <inttypes.h>

extern unsigned long *out;
extern int i;
extern int out_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < out_len; i += 2)
        out[i] = 0;
    // Handle odd-length arrays by setting last element if needed
    if (out_len > 0 && out_len % 2 == 1)
        out[out_len - 1] = 0;
}
