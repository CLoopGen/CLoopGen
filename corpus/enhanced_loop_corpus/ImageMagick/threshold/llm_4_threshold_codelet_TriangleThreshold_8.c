#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double count;
extern ssize_t i;
extern ssize_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)255; i++) {
        max = (histogram[i] > count) ? i : max;
        count = (histogram[i] > count) ? histogram[i] : count;
    }
}
