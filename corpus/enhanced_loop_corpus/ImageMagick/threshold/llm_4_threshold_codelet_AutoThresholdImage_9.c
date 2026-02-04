#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *histogram;
extern double sum;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i <= (ssize_t)255; i++) {
        if (histogram[i] > 0) {
            sum += histogram[i];
        }
    }
}
