#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double h;
extern double * l;
extern double * hprev;
extern size_t ord;
extern size_t i;
extern size_t j;
extern double hsum;
extern double coeff1;
extern double coeff2;
extern double hrelprev;
extern double hrelprod;
extern double hrel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Reverse Memory Access with Prefetching Layout
    // Reverses the order of updates in the inner loop to traverse `l` in strictly decreasing consecutive order.
    // Also reorganizes computation to ensure temporal locality by grouping related operations.
    for (i = 1; i < ord - 1; i++) {
        hsum += hprev[i];
        hrel = hsum / h;
        hrelprod *= hrel;
        coeff1 -= 1. / (i + 1);
        coeff2 += 1. / hrel;

        // Reverse the inner loop to write consecutively from high to low index without back-and-forth
        size_t start = i + 2;
        if (start >= ord) start = ord - 1;  // Clamp to valid range

        // Ensure we don't exceed array bounds and iterate downward consecutively
        for (j = start; j > 1; j--) {
            double temp = l[j - 1];          // Load once for reuse
            l[j] = l[j] * hrelprev + temp;   // Fused multiply-add using previous value
        }

        hrelprev = hrel;
    }
}
