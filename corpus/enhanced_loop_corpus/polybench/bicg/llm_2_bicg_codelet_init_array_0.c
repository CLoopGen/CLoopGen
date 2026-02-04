#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Access elements with a stride of 2, wrapping around using modulo to stay within bounds
    int stride = 2;
    for (i = 0; i < m; i++) {
        int index = (i * stride) % m;
        p[index] = (double)(i % m) / m;
    }
}
