#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2)
        bits[i] = '0';
    // Handle odd-length arrays by filling the last element if needed
    if (len % 2 == 1) {
        bits[len - 1] = '0';
    }
}
