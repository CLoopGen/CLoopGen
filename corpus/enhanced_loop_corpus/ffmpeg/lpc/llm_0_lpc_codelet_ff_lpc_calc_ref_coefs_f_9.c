#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double avg_err;
extern double error[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < order; j++) {
        avg_err = (avg_err + error[j]) / 2.F;
    }
}
