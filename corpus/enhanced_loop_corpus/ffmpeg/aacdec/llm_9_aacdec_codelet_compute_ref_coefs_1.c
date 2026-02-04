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
    LPC_TYPE temp_sum = 0;
    for (j = 0; j < max_order - i; j++) {
        gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
        gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        temp_sum += gen1[j];
    }
    ref[i] = -temp_sum / ((max_order - i) * ((0 || err) ? err : 1));
    err += temp_sum * ref[i];
    if (error)
        error[i] = err;
}
}
