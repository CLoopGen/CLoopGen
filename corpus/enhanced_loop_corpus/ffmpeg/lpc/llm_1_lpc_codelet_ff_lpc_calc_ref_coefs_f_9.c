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
    for (int k = 0; k < order; k++) {
        for (int i = 0; i <= k; i++) {
            avg_err = (avg_err + error[i]) / 2.F;
        }
    }
}
