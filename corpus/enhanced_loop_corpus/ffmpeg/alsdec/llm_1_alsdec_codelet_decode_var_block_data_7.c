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
    if (opt_order > 0) {
        sb = 0;
        for (; sb < opt_order; sb++)
            lpc_cof_reversed[sb] = lpc_cof[-(sb + 1)];
    }
}
