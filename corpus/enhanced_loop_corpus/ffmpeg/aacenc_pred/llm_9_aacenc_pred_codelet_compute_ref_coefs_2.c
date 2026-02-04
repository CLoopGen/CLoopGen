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
    int step;
    for (i = 0; i < max_order; i++) {
        gen0[i] = gen1[i] = autoc[i + 1];
        for (step = 1; step <= 3 && (i + step) < max_order; step++) {
            gen0[i] += autoc[i + step + 1] * 0.1f;
            gen1[i] -= autoc[i + step + 1] * 0.05f;
        }
    }
}
