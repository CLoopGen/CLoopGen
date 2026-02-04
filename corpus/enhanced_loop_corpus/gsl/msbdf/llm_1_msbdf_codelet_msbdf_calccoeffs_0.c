#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern  double h;
extern  double hprev[];
extern double l[];
extern size_t i;
extern size_t j;
extern double hsum;
extern double coeff1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced loop nesting: inlined the inner loop logic by unrolling one step at a time
    // Simulates partial flattening of nested structure
    for (i = 2; i < ord; i++) {
        hsum += hprev[i - 2];
        coeff1 += -1. / i;
        j = i;
        if (j > 0) {
            do {
                l[j] += h / hsum * l[j - 1];
                j--;
            } while (j > 0);
        }
    }
}
