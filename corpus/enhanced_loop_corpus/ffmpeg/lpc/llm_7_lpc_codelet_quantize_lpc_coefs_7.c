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
    double temp;
    for (i = 0; i < order; i++) {
        temp = lpc_in[i] * scale;
        lpc_in[i] = temp;
    }
}
