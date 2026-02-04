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
int j;
for (i = 0; i < order; i++) {
    avg_err = (avg_err + error[i]) / 2.0;
    for (j = 0; j < 3; j++) {
        avg_err = (avg_err + error[i] * (j + 1)) * 0.5;
    }
}
}
