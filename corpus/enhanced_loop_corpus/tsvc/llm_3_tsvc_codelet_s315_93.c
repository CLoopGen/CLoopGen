#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with computed indices)
    // Access pattern follows a scrambled order based on bit reversal for indirect-like behavior
    for (int j = 0; j < 32000; j++) {
        // Compute bit-reversed index of j (for a 15-bit representation, since 2^15 > 32000)
        int i = 0;
        int temp = j;
        for (int bit = 0; bit < 15; bit++) {
            i = (i << 1) | (temp & 1);
            temp >>= 1;
        }
        if (i < 32000) {
            a[i] = (j * 7) % 32000;
        }
    }
}
