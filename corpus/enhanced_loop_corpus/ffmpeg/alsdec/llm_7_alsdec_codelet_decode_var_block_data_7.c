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
    for (sb = opt_order - 1; sb >= 0; sb--)
        lpc_cof_reversed[opt_order - 1 - sb] = lpc_cof[-(sb + 1)];
}
