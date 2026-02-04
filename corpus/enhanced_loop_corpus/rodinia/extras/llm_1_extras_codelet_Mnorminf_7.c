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
if (len > 0) {
    tmp = ((x[0]) >= 0 ? (x[0]) : -(x[0]));
    max_val = tmp;
    for (i = 1; i < len; i++) {
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (max_val < tmp)
            max_val = tmp;
    }
}
}
