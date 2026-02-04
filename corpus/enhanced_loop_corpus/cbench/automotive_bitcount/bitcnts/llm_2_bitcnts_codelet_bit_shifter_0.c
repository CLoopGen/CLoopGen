#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern using a simulated array of bits
    // Instead of directly shifting x, we simulate accessing bits with a stride
    long temp_x = x;
    n = 0;
    for (i = 0; i < (sizeof(long) * 8); i += 2) {
        n += (int)((temp_x >> i) & 1L);
    }
    for (i = 1; i < (sizeof(long) * 8); i += 2) {
        n += (int)((temp_x >> i) & 1L);
    }
}
