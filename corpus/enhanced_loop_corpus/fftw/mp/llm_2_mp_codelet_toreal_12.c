#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern unsigned long r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern simulation
    // We simulate a strided memory access by introducing an array and accessing it with a fixed stride
    // while maintaining the original bit counting logic in a separate control flow.
    
    volatile unsigned long arr[16]; // Simulated memory region
    int stride = 2; // Strided access: every 2nd element
    int idx = 0;
    
    for (bits = 0; r > 0; ++bits) {
        // Perform dummy strided memory accesses proportional to current r's LSB
        idx = (idx + stride) % 16;
        arr[idx] = r; // Strided write access
        r >>= 1;
    }
}
