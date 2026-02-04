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
    double temp_max = max_val;
    for (i = 0; i < len; i++) {
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (temp_max < tmp)
            temp_max = tmp;
    }
    max_val = temp_max;
}
