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
    for (i = 0; i < order; i++) {
        if (lpc_in[i] != 0.0) {
            lpc_in[i] *= scale;
        }
    }
}
