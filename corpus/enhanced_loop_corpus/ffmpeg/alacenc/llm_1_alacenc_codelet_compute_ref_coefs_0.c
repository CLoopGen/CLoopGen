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
    int outer_i;
    int inner_i;
    for (outer_i = 0; outer_i < max_order; outer_i += 2) {
        for (inner_i = outer_i; inner_i < max_order && inner_i < outer_i + 2; inner_i++) {
            i = inner_i;
            gen0[i] = gen1[i] = autoc[i + 1];
        }
    }
}
