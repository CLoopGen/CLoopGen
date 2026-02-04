#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (n = 0; n <= 255 && (n % 2 == 0 ? alphas[n] : 1) == 0; ++n) {
        if (n % 2 != 0) continue;
    }
}
