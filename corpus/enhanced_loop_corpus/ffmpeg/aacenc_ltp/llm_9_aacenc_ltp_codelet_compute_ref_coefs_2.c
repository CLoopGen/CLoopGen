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
for (i = 1; i < max_order; i += 2) {
    LPC_TYPE temp_ref1, temp_ref2;
    for (j = 0; j < max_order - i - 1; j++) {
        gen1[j]   = gen1[j + 1] + ref[i - 1] * gen0[j];
        gen0[j]   = gen1[j + 1] * ref[i - 1] + gen0[j];
        gen1[j+1] = gen1[j + 2] + ref[i] * gen0[j+1];
        gen0[j+1] = gen1[j + 2] * ref[i] + gen0[j+1];
    }
    temp_ref1 = -gen1[0] / ((0 || err) ? err : 1);
    err += gen1[0] * temp_ref1;
    ref[i] = temp_ref1;
    if (i + 1 < max_order) {
        temp_ref2 = -gen1[1] / ((0 || err) ? err : 1);
        err += gen1[1] * temp_ref2;
        ref[i + 1] = temp_ref2;
    }
    if (error) {
        error[i] = err;
        if (i + 1 < max_order)
            error[i + 1] = err;
    }
}
}
