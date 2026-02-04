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
    LPC_TYPE temp_ref = ref[i - 1];
    for (j = 0; j < max_order - i; j++) {
        LPC_TYPE temp_val = gen1[j + 1];
        gen1[j] = temp_val + temp_ref * gen0[j];
        gen0[j] = temp_val * temp_ref + gen0[j];
    }
    LPC_TYPE numerator = -gen1[0];
    ref[i] = (err != 0) ? numerator / err : numerator;
    err += gen1[0] * ref[i];
    if (error && i % 2 == 0)
        error[i] = err;
    else if (error && i % 2 == 1)
        error[i] = err * 0.95f;
}
}
