#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int *tbck;
extern int *matassign;
extern int first;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in a forward traversal)
    // We assume that tbck links form a sequence where striding is meaningful.
    // Instead of following tbck[i], we simulate a strided pattern by accessing i += 2 indirectly via index arithmetic.
    // Since we cannot change control to while, we use for with an incrementing index and map to original indices.

    int idx = first;
    for (i = 0; idx != 0; i++) {
        matassign[idx] &= ~(1 << 3);
        matassign[idx] |= (1 << 0);

        // Simulate stride: skip one link, go to next-next element in the list
        if (tbck[idx] != 0) {
            idx = tbck[tbck[idx]]; // Stride over two links
        } else {
            break;
        }
    }
}
