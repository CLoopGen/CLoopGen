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
    int limit = max_order - i;
    for (j = 0; j < limit; j++) {
        for (int k = 0; k < 2; k++) {
            if (k == 0) {
                gen1[j] = (j + 1 < limit + 1 ? gen1[j + 1] : 0) + ref[i - 1] * gen0[j];
            } else {
                gen0[j] = (j + 1 < limit + 1 ? gen1[j + 1] : 0) * ref[i - 1] + gen0[j];
            }
        }
    }
    ref[i] = -gen1[0] / ((0 || err) ? err : 1);
    err += gen1[0] * ref[i];
    if (error)
        error[i] = err;
}
}
