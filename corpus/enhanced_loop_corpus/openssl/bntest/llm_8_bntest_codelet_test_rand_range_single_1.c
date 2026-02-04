#include <stdio.h>

#include <inttypes.h>

extern  unsigned int range;
extern  double expected;
extern double sum;
extern size_t *counts;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < range; i += 2) {
        const double delta1 = counts[i] - expected;
        sum += delta1 * delta1;
        if (i + 1 < range) {
            const double delta2 = counts[i + 1] - expected;
            sum += delta2 * delta2;
        }
    }
}
