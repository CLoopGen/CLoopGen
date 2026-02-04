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
    for (i = 0; i < len; i += 2) {
        double val1 = x[i];
        double abs1 = (val1 >= 0) ? val1 : -val1;
        sum += abs1;
        if (i + 1 < len) {
            double val2 = x[i + 1];
            double abs2 = (val2 >= 0) ? val2 : -val2;
            sum += abs2;
        }
    }
}
