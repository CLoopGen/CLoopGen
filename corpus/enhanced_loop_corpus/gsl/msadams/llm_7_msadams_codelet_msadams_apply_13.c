#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_val = hprev[0];
    for (i = 1; i < 12; i++) {
        double current_val = hprev[i];
        hprev[i] = prev_val;
        prev_val = current_val;
    }
}
