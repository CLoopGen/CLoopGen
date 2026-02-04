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
for (i = 1; i < max_order && i < 16; i++) {
    LPC_TYPE temp_ref = ref[i - 1];
    for (j = 0; j < max_order - i; j++) {
        LPC_TYPE update = gen1[j + 1] + temp_ref * gen0[j];
        gen0[j] = temp_ref * gen1[j + 1] + gen0[j];
        gen1[j] = update;
    }
    LPC_TYPE inv_denom = (err != 0.0) ? err : 1.0;
    ref[i] = -gen1[0] / inv_denom;
    err += gen1[0] * ref[i];
    if (error)
        error[i] = err;
}
}
