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
    for (int j = 0; j < max_order; j++) {
        for (int k = 0; k < 1; k++) {
            gen0[j] = gen1[j] = autoc[j + 1];
        }
    }
}
