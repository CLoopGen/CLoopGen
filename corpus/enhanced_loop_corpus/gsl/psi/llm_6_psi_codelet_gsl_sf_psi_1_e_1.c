#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int M;
extern double sum;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (m = 0; m < M; ++m) {
        temp_sum += 1. / ((x + m) * (x + m));
    }
    sum = temp_sum;
}
