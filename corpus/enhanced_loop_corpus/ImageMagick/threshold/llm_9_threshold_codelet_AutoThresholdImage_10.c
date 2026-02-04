#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double gamma;
extern double *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)511; i++) {
        double temp = gamma * histogram[i % 256];
        histogram[i % 256] = temp * temp;
    }
}
