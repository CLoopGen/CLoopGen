#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nin;
extern int i;
extern int nop;
extern int iter_ndim;
extern int op_core_num_dims[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    // This variant accesses every second element first, then the others, simulating a strided pattern
    int sum = 0;
    // First pass: even indices starting from nin if even
    int start = nin % 2 == 0 ? nin : nin + 1;
    for (i = start; i < nop; i += 2) {
        sum += op_core_num_dims[i];
    }
    // Second pass: odd indices starting from nin if odd
    start = nin % 2 == 1 ? nin : nin + 1;
    for (i = start; i < nop; i += 2) {
        sum += op_core_num_dims[i];
    }
    iter_ndim += sum;
}
