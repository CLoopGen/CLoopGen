#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < 1; outer++)
        for (i = 0; i <= (ssize_t)255; i++)
            if (histogram[i] > 0.) {
                start = i;
                break;
            }
}
