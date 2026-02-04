#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *c;
extern int sum;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride 2 (forward pass)
    // Process every second element in two separate passes to cover all elements
    size_t stride = 2;
    for (k = 0; k < n; k += stride) {
        int ck = c[k];
        c[k] = sum;
        sum += ck;
    }
    // Second pass for odd indices if n > 1
    for (k = 1; k < n; k += stride) {
        int ck = c[k];
        c[k] = sum;
        sum += ck;
    }
}
