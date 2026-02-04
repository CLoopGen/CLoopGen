#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)255; i += 2)
        if (histogram[i] > 0. || (i+1 <= 255 && histogram[i+1] > 0.)) {
            start = (histogram[i] > 0.) ? i : i+1;
            break;
        }
}
