#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int sb;
extern int32_t *lpc_cof;
extern int32_t *lpc_cof_reversed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_sum = 0;
    for (sb = 0; sb < opt_order * 2; sb++) {
        int idx = sb / 2;
        temp_sum += lpc_cof[-(idx + 1)] * (sb % 2 ? 3 : 7);
        if (sb % 2) {
            lpc_cof_reversed[idx] = temp_sum;
            temp_sum = 0;
        }
    }
}
