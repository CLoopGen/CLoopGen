#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access - process every other element in two passes (forward and backward stride simulation)
    // First handle even indices in forward order, then odd in reverse to create varied access pattern
    for (i = 0; i < 32; i += 2) {
        e[2 * i + 0] = (a[i] >> 0) & 15;
        e[2 * i + 1] = (a[i] >> 4) & 15;
    }
    for (i = 31; i >= 1; i -= 2) {
        e[2 * i + 0] = (a[i] >> 0) & 15;
        e[2 * i + 1] = (a[i] >> 4) & 15;
    }
}
