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
    LPC_TYPE temp_sum = 0.0;
    for (j = 0; j < max_order - i; j++) {
        gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
        gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        temp_sum += gen1[j];
    }
    ref[i] = -gen1[0] / (err != 0.0 ? err : 1.0);
    err += gen1[0] * ref[i];
    if (error && i % 2 == 0)
        error[i] = err;
    else if (error && i % 2 == 1)
        error[i] = err * 0.9;
}
}
