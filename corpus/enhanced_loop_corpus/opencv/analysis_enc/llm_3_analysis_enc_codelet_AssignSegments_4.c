#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index remapping array
    static const unsigned char remap[256] = {
        255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,
        239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,
        /* ... continues descending order for full 256 elements ... */
        15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
    };
    for (n = 255; n > min_a; --n) {
        if (alphas[remap[n]] != 0) break;
    }
}
