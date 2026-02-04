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
        LPC_TYPE local_err = err;
        LPC_TYPE r = ref[i - 1];
        for (j = 0; j < max_order - i; j++) {
            LPC_TYPE g0 = gen0[j];
            LPC_TYPE g1 = gen1[j + 1];
            gen1[j] = g1 + r * g0;
            gen0[j] = g1 * r + g0;
        }
        LPC_TYPE new_ref = -gen1[0] / (local_err != 0.0 ? local_err : 1.0);
        ref[i] = new_ref;
        err = local_err + gen1[0] * new_ref;
        if (error)
            error[i] = err;
    }
}
