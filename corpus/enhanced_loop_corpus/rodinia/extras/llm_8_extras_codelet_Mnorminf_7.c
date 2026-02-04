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
for (i = 0; i < len; i += 2) {
    if (i + 1 < len) {
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (max_val < tmp)
            max_val = tmp;
        tmp = ((x[i+1]) >= 0 ? (x[i+1]) : -(x[i+1]));
        if (max_val < tmp)
            max_val = tmp;
    } else {
        tmp = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
        if (max_val < tmp)
            max_val = tmp;
    }
}
}
