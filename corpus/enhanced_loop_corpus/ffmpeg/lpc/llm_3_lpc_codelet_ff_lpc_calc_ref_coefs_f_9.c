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
    // Variant 2: Reverse consecutive memory access
    // This variant traverses the error array from the last element to the first.
    for (i = order - 1; i >= 0; i--) {
        avg_err = (avg_err + error[i]) / 2.F;
    }
}
