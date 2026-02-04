#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < range; ++i) {
        const double delta = counts[i] - expected;
        sum += delta * delta * 1.5; // Increased arithmetic intensity
    }
}
