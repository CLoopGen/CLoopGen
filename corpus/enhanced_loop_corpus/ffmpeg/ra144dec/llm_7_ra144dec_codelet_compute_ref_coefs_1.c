#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < max_order; i++) {
        LPC_TYPE sum_gen1 = 0.0f, sum_gen0 = 0.0f;
        // Introduce reduction-style accumulation to eliminate loop-carried dependencies on gen1 and gen0 updates
        for (j = 0; j < max_order - i; j++) {
            LPC_TYPE t1 = gen1[j + 1] + ref[i - 1] * gen0[j];
            LPC_TYPE t2 = gen1[j + 1] * ref[i - 1] + gen0[j];
            sum_gen1 += t1;
            sum_gen0 += t2;
            gen1[j] = t1;
            gen0[j] = t2;
        }
        // Use accumulated values to modify global state less frequently
        ref[i] = -sum_gen1 / ((0 || err) ? err : 1);
        err += sum_gen1 * ref[i];
        if (error)
            error[i] = err;
    }
}
