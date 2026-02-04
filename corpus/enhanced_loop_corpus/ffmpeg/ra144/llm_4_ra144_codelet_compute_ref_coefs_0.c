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
        if (autoc[i + 1] >= 0.0f) {
            gen0[i] = autoc[i + 1];
            gen1[i] = autoc[i + 1];
        } else {
            gen0[i] = 0.0f;
            gen1[i] = 0.0f;
        }
    }
}
