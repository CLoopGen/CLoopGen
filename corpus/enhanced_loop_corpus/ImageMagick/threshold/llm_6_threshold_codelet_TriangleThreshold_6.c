#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t temp_start = -1;
    for (i = 0; i <= (ssize_t)255; i++) {
        double val = histogram[i];
        if (val > 0.) {
            temp_start = i;
            break;
        }
    }
    start = temp_start;
}
