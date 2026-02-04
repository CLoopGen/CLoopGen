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
        gen0[i] = gen1[i] = autoc[i + 1];
        for (j = 1; j < 4 && (i + j) < max_order; j++) {  // Introduce small inner loop
            gen1[i] += autoc[i + j] * 0.5f;  // Additional computation to increase intensity
        }
    }
}
