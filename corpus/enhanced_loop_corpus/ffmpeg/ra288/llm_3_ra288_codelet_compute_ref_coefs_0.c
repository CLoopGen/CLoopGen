#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reversed read access pattern
    int rev_index;
    for (i = 0; i < max_order; i++) {
        rev_index = max_order - i - 1;  // Reverse index for autoc
        gen0[i] = gen1[i] = autoc[rev_index + 1];
    }
}
