#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int32_t *local_res = res;
    int32_t *local_smp = smp;
    int local_order = order;

    for (i = 0; i < local_order; i += 2) {
        if (i + 1 < local_order) {
            local_res[i] = local_smp[i];
            local_res[i + 1] = local_smp[i + 1];
        } else {
            local_res[i] = local_smp[i];
        }
    }
}
