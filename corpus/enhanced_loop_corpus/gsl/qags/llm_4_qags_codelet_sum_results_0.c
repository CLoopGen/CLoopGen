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
    for (k = 0; k < n; k++) {
        if (rlist[k] > 0.0) {
            result_sum += rlist[k];
        }
    }
}
