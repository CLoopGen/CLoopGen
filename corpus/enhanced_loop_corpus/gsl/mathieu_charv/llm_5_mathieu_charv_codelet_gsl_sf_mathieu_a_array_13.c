#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order_min;
extern int order_max;
extern double result_array[];
extern unsigned int ii;
extern double *aa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = order_min; ii <= order_max; ii++) {
        if ((ii - order_min) >= 0) {
            result_array[ii - order_min] = aa[ii];
        }
    }
}
