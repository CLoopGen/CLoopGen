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
    for (sb = 0; sb < opt_order; sb++) {
        int index = -(sb + 1);
        if (index < 0) {
            lpc_cof_reversed[sb] = lpc_cof[index];
        }
    }
}
