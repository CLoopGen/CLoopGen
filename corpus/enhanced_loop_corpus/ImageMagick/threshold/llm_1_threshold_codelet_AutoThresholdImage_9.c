#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *histogram;
extern double sum;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t k = 0; k <= (ssize_t)1; k++) {
        for (i = 0; i <= (ssize_t)255; i++) {
            sum += histogram[i];
        }
    }
}
