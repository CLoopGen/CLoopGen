#include <stdio.h>

#include <inttypes.h>

extern unsigned long accum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long arr[2] = {accum, accum};
    size_t idx = 0;
    for (i = 0; arr[idx] >>= 1; ++i)
        idx ^= 1; // Toggle between index 0 and 1 (strided access pattern)
}
