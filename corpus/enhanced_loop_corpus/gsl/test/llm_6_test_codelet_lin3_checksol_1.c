#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = 1; i < 10 - 1; ++i) {
        temp_sum += (i + 1.) * x[i];
    }
    sum += temp_sum;
}
