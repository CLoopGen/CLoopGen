#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse array from end to start)
    for (i = range; i > 0; --i) {
        const size_t idx = i - 1; // Convert to zero-based index
        const double delta = counts[idx] - expected;
        sum += delta * delta;
    }
}
