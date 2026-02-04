#include <stdio.h>

#include <inttypes.h>

extern int base;
extern int count;
extern unsigned int parts[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolling-like pattern)
    // Access parts array in strides of 2, processing even indices first, then odd
    int limit = (((8 * 8) / 8) * 2);
    for (count = 0; count < limit; count += 2) {
        // Process even index
        int idx = count;
        parts[idx] *= base;
        if (idx) {
            parts[idx] += (parts[idx - 1] >> 8);
            parts[idx - 1] &= (1 << 8) - 1;
        } else {
            parts[0] += n;
        }
        // Process odd index if within bounds
        idx = count + 1;
        if (idx < limit) {
            parts[idx] *= base;
            if (idx) {
                parts[idx] += (parts[idx - 1] >> 8);
                parts[idx - 1] &= (1 << 8) - 1;
            } else {
                parts[0] += n;
            }
        }
    }
}
