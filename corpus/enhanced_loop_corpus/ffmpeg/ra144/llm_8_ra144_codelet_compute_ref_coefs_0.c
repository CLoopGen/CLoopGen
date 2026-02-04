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
    int j;
    for (i = 0; i < max_order; i++) {
        gen0[i] = autoc[i + 1] * 2.0f;
        gen1[i] = autoc[i + 1] + 1.0f;
    }
    for (j = 0; j < max_order && max_order > 16; j++) {
        gen0[j] += gen1[max_order - j - 1];
    }
}
