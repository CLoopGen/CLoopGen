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
    double temp_avg = avg_err;
    for (i = 0; i < order; i++)
        temp_avg = (temp_avg + error[i]) / 2.0;
    avg_err = temp_avg;
}
