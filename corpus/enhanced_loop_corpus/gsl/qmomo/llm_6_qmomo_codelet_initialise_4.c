#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_rj, temp_rh;
    for (i = 1; i < 25; i += 2) {
        temp_rj = rj[i];
        temp_rh = rh[i];
        rj[i] = -temp_rh;  
        rh[i] = -temp_rj;  
    }
}
