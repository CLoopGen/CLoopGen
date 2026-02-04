#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        dst[i] = 0;
    }
    // Handle odd-length arrays by setting last element if needed
    if (len > 0 && (len % 2) == 1) {
        dst[len - 1] = 0;
    }
}
