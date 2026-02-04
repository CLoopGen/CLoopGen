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
    count = histogram[0];
    max = 0;
    for (i = 1; i <= (ssize_t)255; i++) {
        double val = histogram[i];
        ssize_t greater = (val > count);
        max = greater * i + (1 - greater) * max;
        count = greater * val + (1 - greater) * count;
    }
}
