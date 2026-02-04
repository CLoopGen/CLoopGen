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
    // Eliminate loop-carried dependencies and restructure to allow potential unrolling/vectorization
    // Split the original assignment into two independent loops (unrolled style)
    for (i = 0; i < max_order; i++)
        gen0[i] = autoc[i + 1];
    for (i = 0; i < max_order; i++)
        gen1[i] = autoc[i + 1]; // Remove dependency on gen0; both now depend only on autoc
}
