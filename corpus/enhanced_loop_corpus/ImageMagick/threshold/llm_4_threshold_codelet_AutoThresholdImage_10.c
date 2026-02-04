#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double gamma;
extern double *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)255; i++) {
        if (histogram[i] != 0.0) {
            histogram[i] = gamma * histogram[i];
        }
    }
}
