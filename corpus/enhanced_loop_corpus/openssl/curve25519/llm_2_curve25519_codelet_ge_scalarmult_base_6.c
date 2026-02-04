#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled loop (2 elements per iteration)
    for (i = 0; i < 32; ++i) {
        uint8_t val = a[i];
        e[i * 2 + 0] = val & 15;
        e[i * 2 + 1] = (val >> 4) & 15;
    }
}
