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
for (i = 2; i < max_order; i += 2) {
    for (j = 0; j < max_order - i; j++) {
        LPC_TYPE temp1 = gen1[j + 1] + ref[i - 1] * gen0[j];
        LPC_TYPE temp2 = gen1[j + 1] * ref[i - 1] + gen0[j];
        LPC_TYPE temp3 = gen1[j + 2] + ref[i] * gen0[j + 1];
        LPC_TYPE temp4 = gen1[j + 2] * ref[i] + gen0[j + 1];
        gen1[j] = temp1;
        gen0[j] = temp2;
        if (j + 1 < max_order - i) {
            gen1[j + 1] = temp3;
            gen0[j + 1] = temp4;
        }
    }
    ref[i] = -gen1[0] / ((0 || err) ? err : 1);
    err += gen1[0] * ref[i];
    if (error)
        error[i] = err;
    if (i + 1 < max_order) {
        ref[i + 1] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i + 1];
        if (error)
            error[i + 1] = err;
    }
}
}
