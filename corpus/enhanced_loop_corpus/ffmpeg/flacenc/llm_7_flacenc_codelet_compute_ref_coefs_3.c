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
        for (j = 0; j < max_order - i; j++) {
            int idx = j + 1;
            LPC_TYPE t1 = gen1[idx] + ref[i - 1] * gen0[j];
            LPC_TYPE t2 = gen1[idx] * ref[i - 1] + gen0[j];
            sum_gen1 += t1;
            sum_gen0 += t2;
            gen1[j] = t1;
            gen0[j] = t2;
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
