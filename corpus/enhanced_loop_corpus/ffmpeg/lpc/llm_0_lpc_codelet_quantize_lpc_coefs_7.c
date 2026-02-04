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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < order; i++) {
            lpc_in[i] *= scale;
        }
    }
}
