#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int fixed_exp_table[7];
extern int x;
extern int i;
extern int ret;
extern int xpow;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates irregular access pattern)
    // Define a static index mapping that reorders array access (e.g., permutation of indices)
    static const int index_map[7] = {6, 4, 2, 0, 1, 3, 5}; // Access in shuffled order
    for (i = 0; i < 7; i++) {
        int idx = index_map[i]; // Indirect access via lookup
        xpow = (int)(((int64_t)xpow * x + 4194304) >> 23);
        tmp = (int)(((int64_t)xpow * fixed_exp_table[idx] + 1073741824) >> 31);
        ret += tmp;
    }
}
