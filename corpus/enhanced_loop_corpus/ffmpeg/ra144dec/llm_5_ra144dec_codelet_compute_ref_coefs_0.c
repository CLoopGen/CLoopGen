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
    for (i = 0; i < max_order; i++) {
        LPC_TYPE val = autoc[i + 1];
        gen0[i] = val;
        if (i % 2 == 0) {
            gen1[i] = val;
        } else {
            gen1[i] = val * 0.5f;
        }
    }
}
