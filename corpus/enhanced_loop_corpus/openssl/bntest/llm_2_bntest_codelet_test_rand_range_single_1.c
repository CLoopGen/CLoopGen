#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    for (i = 0; i < range; i += 2) {
        const double delta1 = counts[i] - expected;
        sum += delta1 * delta1;
        
        // Handle boundary to stay within valid range
        if (i + 1 < range) {
            const double delta2 = counts[i + 1] - expected;
            sum += delta2 * delta2;
        }
    }
}
