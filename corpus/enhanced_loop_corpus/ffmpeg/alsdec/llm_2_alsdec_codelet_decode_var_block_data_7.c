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
    int stride = 2;
    for (sb = 0; sb < opt_order; sb += stride) {
        if (sb < opt_order) {
            lpc_cof_reversed[sb] = lpc_cof[-(sb + 1)];
        }
    }
}
