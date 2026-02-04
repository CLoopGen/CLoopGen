#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *probability;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (j = 0; j <= (ssize_t)255; j++) {
        probability[j] = histogram[j];
        if (j > 0)
            probability[j] += probability[j - 1] * 0.001; // Introduce WAW and RAW dependency: current depends on previous write
    }
}
