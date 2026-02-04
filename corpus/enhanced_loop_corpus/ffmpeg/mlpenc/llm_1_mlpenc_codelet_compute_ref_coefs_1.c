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
        for (i = 0; i < max_order; i += 2) {
            gen0[i] = gen1[i] = autoc[i + 1];
            if (i + 1 < max_order) {
                gen0[i + 1] = gen1[i + 1] = autoc[i + 2];
            }
        }
    }
}
