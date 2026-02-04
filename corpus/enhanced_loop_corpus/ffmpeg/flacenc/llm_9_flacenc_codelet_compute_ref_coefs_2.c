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
    int limit = max_order > 16 ? 16 : max_order;
    for (i = 0; i < limit; i++) {
        LPC_TYPE temp = autoc[i + 1] + autoc[i];
        gen0[i] = temp * 0.7f;
        gen1[i] = temp * 0.3f;
    }
    for (i = limit; i < max_order; i++) {
        gen0[i] = gen1[i] = autoc[i + 1] - autoc[i];
    }
}
