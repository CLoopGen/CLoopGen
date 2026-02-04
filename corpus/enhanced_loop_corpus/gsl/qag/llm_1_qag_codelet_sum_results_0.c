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
    if (n > 0) {
        for (k = 0; k < n / 2; k++) {
            result_sum += rlist[k] + rlist[n - 1 - k];
        }
        if (n % 2 == 1) {
            result_sum += rlist[n / 2];
        }
    }
}
