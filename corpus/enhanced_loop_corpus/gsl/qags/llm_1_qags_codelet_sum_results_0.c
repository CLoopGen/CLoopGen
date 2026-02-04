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
    size_t outer_n = (n + 1) / 2;
    for (k = 0; k < outer_n; k++) {
        result_sum += rlist[2 * k];
        if ((2 * k + 1) < n) {
            result_sum += rlist[2 * k + 1];
        }
    }
}
