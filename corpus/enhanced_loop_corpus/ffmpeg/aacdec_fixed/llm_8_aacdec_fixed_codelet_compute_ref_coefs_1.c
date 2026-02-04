#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < max_order && i < 32; i++) {
        gen0[i] = autoc[i + 1] + 1;
        gen1[i] = autoc[i + 1] - 1;
        for (j = 0; j < 3; j++) {
            gen0[i] *= 2;
            gen1[i] /= 2;
        }
    }
}
