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
    size_t inner_n = 2;
    for (k = 0; k < outer_n; k++) {
        for (size_t j = 0; j < inner_n; j++) {
            size_t idx = k * 2 + j;
            if (idx < n) {
                result_sum += rlist[idx];
            }
        }
    }
}
