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
    sum = 0.0;
    for (m = 0; m < M; ++m) {
        double denom = x + m;
        if (denom != 0.0) {
            sum += 1.0 / (denom * denom);
        }
    }
}
