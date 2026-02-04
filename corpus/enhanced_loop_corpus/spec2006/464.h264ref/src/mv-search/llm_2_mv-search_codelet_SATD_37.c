#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a folded manner)
    // We simulate a strided pattern by accessing diff with step size 2, wrapping around using modulo
    int idx;
    for (k = 0; k < 16; k++) {
        idx = (k * 2) % 16;  // Strided access: 0, 2, 4, ..., 14, 0, 2, ... (but only up to 16 iterations)
        satd += byte_abs[diff[idx]];
    }
}
