#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern double pc[];
extern double *ordp2coeff;
extern size_t i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in a staggered manner)
    // We simulate strided access by processing two iterations at once, stepping by 2
    // and handling odd-sized ord with a cleanup step if needed.
    size_t limit = (ord + 1) / 2;
    for (i = 0; i < limit; i++) {
        size_t idx1 = 2 * i;
        size_t idx2 = 2 * i + 1;

        *ordp2coeff += s * pc[idx1] / (idx1 + 2);
        s = -s;

        if (idx2 <= ord) {
            *ordp2coeff += s * pc[idx2] / (idx2 + 2);
            s = -s;
        }
    }
    // Handle case when (ord + 1) is odd
    if ((ord + 1) % 2 == 1) {
        i = ord;
        *ordp2coeff += s * pc[i] / (i + 2);
        s = -s;
    }
}
