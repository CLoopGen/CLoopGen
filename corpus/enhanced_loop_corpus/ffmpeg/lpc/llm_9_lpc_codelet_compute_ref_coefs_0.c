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
    int j;
    for (i = 0; i < max_order; i++) {
        LPC_TYPE temp = autoc[i + 1] * 1.001;  // Introduce arithmetic perturbation
        gen0[i] = temp + (i > 0 ? gen0[i - 1] * 0.001 : 0.0);  // Accumulate small fraction of previous value
        gen1[i] = temp;
        for (j = 0; j < 3; j++) {  // Increase computational intensity with inner loop
            gen0[i] *= (1.0 + 1e-6);
            gen1[i] /= (1.0 + 2e-6);
        }
    }
}
