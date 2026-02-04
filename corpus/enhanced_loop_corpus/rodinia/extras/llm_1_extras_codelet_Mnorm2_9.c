#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double invnorm;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int block_size = 16;
    for (outer_i = 0; outer_i < len; outer_i += block_size) {
        for (inner_i = outer_i; inner_i < len && inner_i < outer_i + block_size; inner_i++) {
            i = inner_i;
            tmp = x[i] * invnorm;
            sum += tmp * tmp;
        }
    }
}
