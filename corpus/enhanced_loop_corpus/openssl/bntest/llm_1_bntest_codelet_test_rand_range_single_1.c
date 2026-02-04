#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < range; outer += 1) {
        for (size_t inner = outer; inner < outer + 1 && inner < range; ++inner) {
            const double delta = counts[inner] - expected;
            sum += delta * delta;
        }
    }
}
