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
    int outer, inner;
    int block_size = 4;
    for (outer = 0; outer < max_order; outer += block_size) {
        for (inner = outer; inner < outer + block_size && inner < max_order; inner++) {
            i = inner;
            gen0[i] = gen1[i] = autoc[i + 1];
        }
    }
}
