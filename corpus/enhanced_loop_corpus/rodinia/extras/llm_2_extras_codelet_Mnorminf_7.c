#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double tmp;
extern double max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (max_val < tmp)
            max_val = tmp;
    }
    // Handle odd-length array by processing last element if needed
    if (len % 2 == 1) {
        i = len - 1;
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (max_val < tmp)
            max_val = tmp;
    }
}
