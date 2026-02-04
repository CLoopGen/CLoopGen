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
    if (max_order > 0) {
        i = 0;
        for (int step = max_order; step > 0; step >>= 1) {
            while (i < max_order && step == 1) {
                gen0[i] = gen1[i] = autoc[i + 1];
                i++;
            }
        }
    }
}
