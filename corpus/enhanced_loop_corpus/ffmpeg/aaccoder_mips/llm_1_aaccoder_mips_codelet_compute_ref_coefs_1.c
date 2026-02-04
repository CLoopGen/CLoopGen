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
    int tile = 16;
    for (outer = 0; outer < max_order; outer += tile) {
        for (inner = outer; inner < max_order && inner < outer + tile; inner++) {
            i = inner;
            gen0[i] = gen1[i] = autoc[i + 1];
        }
    }
}
