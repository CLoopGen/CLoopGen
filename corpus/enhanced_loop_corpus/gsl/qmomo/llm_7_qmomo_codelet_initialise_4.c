#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_rj = rj[1], prev_rh = rh[1];
    rj[1] *= -1;
    rh[1] *= -1;
    for (i = 3; i < 25; i += 2) {
        rj[i] *= -prev_rj;
        rh[i] *= -prev_rh;
        prev_rj = rj[i];
        prev_rh = rh[i];
    }
}
