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
for (int k = 0; k < M; ++k)
    for (m = k; m < k + 1; ++m)
        sum += 1. / ((x + m) * (x + m));
}
