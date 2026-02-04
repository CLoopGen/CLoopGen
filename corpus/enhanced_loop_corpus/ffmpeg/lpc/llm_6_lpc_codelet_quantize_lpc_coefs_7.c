#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *lpc_in;
extern int order;
extern int i;
extern double scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_ptr = lpc_in;
    double local_scale = scale;
    int local_order = order;
    for (i = 0; i < local_order; i++) {
        local_ptr[i] *= local_scale;
    }
}
