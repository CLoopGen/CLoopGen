#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double alpha;
extern double *x;
extern double *y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        y[0] += alpha * x[0];
        for (i = 1; i < len; i++) {
            y[i] += alpha * x[i] + (y[i-1] - y[i-1]); // Introduces artificial RAW and WAW dependency with no semantic change
        }
    }
}
