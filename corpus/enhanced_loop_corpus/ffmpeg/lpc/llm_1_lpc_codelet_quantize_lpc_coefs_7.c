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
    if (order > 0) {
        for (i = 0; i < order; i += 2) {
            lpc_in[i] *= scale;
            if (i + 1 < order) {
                lpc_in[i + 1] *= scale;
            }
        }
    }
}
