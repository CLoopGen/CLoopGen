#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern  int M;
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (n = 1; n <= M; n++) {
        temp_sum += 1. / (n * (n * n + y * y));
    }
    sum = temp_sum;
}
