#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    int stride = 2;
    for (n = 255; n > min_a && (n % stride == 0 ? alphas[n] : 1) == 0; --n) {
        if (n % stride != 0) continue;
    }
}
