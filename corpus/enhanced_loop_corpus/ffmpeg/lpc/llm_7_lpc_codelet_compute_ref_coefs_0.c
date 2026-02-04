#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < max_order; i++) {
        gen0[i] = autoc[i + 1];
        if (i > 0) {
            gen1[i - 1] = gen0[i]; // Introduce RAW dependency: gen1[i-1] depends on gen0[i]
        }
        gen1[i] = autoc[i + 1];
    }
    if (max_order > 0) {
        gen1[max_order - 1] = autoc[max_order]; // Final assignment to maintain semantic closeness
    }
}
