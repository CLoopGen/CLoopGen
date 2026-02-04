#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double * rlist;
extern  size_t n;
extern size_t k;
extern double result_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result_sum = 0.0;
    for (k = 0; k < n; k += 2) {
        double val1 = rlist[k];
        double val2 = (k + 1 < n) ? rlist[k + 1] : 0.0;
        result_sum += val1 + val2;
    }
}
