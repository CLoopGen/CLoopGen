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
    double local_max = max_val;
    for (i = 0; i < len; i += 2) {
        double val1 = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        double val2 = (i + 1 < len) ? ((x[i+1]) >= 0 ? (x[i+1]) : -(x[i+1])) : val1;
        if (val1 > val2) {
            if (local_max < val1)
                local_max = val1;
        } else {
            if (local_max < val2)
                local_max = val2;
        }
    }
    max_val = local_max;
}
