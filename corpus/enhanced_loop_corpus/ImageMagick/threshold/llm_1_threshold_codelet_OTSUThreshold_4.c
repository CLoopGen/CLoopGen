#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *probability;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= (ssize_t)255; i += 2) {
        probability[i] = histogram[i];
        if (i + 1 <= 255)
            probability[i + 1] = histogram[i + 1];
    }
}
