#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < len * 2; i += 2) {
        if (i / 2 < len) {
            double val = x[i / 2];
            sum += val >= 0 ? val : -val;
        }
    }
}
