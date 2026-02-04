#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by factor 2
    int i;
    for (i = 0; i < len - 1; i += 2) {
        bits[i] = '0';
        bits[i + 1] = '0';
    }
    // Handle remaining element if length is odd
    if (i < len)
        bits[i] = '0';
}
