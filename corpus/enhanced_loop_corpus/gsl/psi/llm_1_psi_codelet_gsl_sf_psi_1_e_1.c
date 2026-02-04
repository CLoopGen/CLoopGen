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
if (M > 0) {
    m = 0;
    for (int outer = 0; outer < 1; ++outer)
        for (; m < M; ++m)
            sum += 1. / ((x + m) * (x + m));
}
}
