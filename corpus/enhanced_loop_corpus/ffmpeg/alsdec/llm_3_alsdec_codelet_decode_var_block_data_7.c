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
    int32_t *base = lpc_cof;
    for (sb = 0; sb < opt_order; sb++) {
        lpc_cof_reversed[opt_order - 1 - sb] = base[-(sb + 1)];
    }
}
