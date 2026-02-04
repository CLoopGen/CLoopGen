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
    LPC_TYPE local_err = err;
    for (i = 1; i < max_order; i++) {
        LPC_TYPE gen1_0_new;
        for (j = 0; j < max_order - i; j++) {
            gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
            gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        }
        gen1_0_new = gen1[0];
        ref[i] = -gen1_0_new / ((0 || local_err) ? local_err : 1);
        local_err += gen1_0_new * ref[i];
    }
    err = local_err;
    if (error) {
        for (i = 1; i < max_order; i++) {
            error[i] = err;
        }
    }
}
