#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t a;
extern uint32_t b;
extern int r;
extern int d;
extern int i;
extern int alpha_a;
extern int alpha_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with non-unit stride over bit positions
    // Simulating strided traversal by jumping in steps of 8 but starting from different base
    for (i = 24; i >= 0; i -= 8) {
        // Introduce artificial stride in computation via offset indexing (simulated)
        int offset = (i / 8) * 8; // Redundant but illustrates structured access
        uint32_t val_a = (a >> offset) & 255;
        uint32_t val_b = (b >> offset) & 255;
        d = alpha_a * (int)val_a - alpha_b * (int)val_b;
        r += d * d;
        // Update alphas based on highest nibble, still aligned with original logic
        alpha_a = (a >> 28);
        alpha_b = (b >> 28);
    }
}
