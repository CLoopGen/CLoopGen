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
    LPC_TYPE temp;
    for (i = 0; i < max_order; i++) {
        temp = autoc[i + 1];
        gen0[i] = temp;
        gen1[i] = temp;
    }
}
