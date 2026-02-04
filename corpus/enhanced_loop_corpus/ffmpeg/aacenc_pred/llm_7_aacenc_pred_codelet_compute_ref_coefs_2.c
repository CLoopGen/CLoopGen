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
    if (max_order > 0) {
        gen0[0] = gen1[0] = autoc[1];
        for (i = 1; i < max_order; i++) {
            gen0[i] = gen1[i-1]; // Introduce RAW and WAW dependency: gen1[i-1] read after write in previous iteration
            gen1[i] = autoc[i + 1];
        }
    }
}
