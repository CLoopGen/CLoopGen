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
    avg_err = 0.0;
    for (i = 0; i < order; i++) {
        avg_err += error[i];
    }
    avg_err /= order > 0 ? order : 1;
}
