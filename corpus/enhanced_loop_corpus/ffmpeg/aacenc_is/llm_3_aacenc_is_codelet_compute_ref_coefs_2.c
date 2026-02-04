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
    ptrdiff_t offset = 0;
    for (j = 0; j < max_order - i; j++, offset++) {
        LPC_TYPE* base_gen0 = &gen0[offset];
        LPC_TYPE* base_gen1 = &gen1[offset];
        LPC_TYPE val_gen1_next = *(base_gen1 + 1);
        *(base_gen1) = val_gen1_next + ref[i - 1] * (*base_gen0);
        (*base_gen0) = val_gen1_next * ref[i - 1] + (*base_gen0);
    }
    ref[i] = -gen1[0] / ((0 || err) ? err : 1);
    err += gen1[0] * ref[i];
    if (error)
        error[i] = err;
}
}
