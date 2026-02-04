#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order_min;
extern int order_max;
extern double result_array[];
extern unsigned int ii;
extern double *bb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (order_min <= order_max) {
        ii = order_min;
        for (int stride = (order_max - order_min + 1); stride > 0; stride--) {
            result_array[ii - order_min] = bb[ii];
            ii++;
        }
    }
}
