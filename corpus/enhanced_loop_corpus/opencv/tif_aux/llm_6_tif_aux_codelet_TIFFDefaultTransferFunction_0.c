#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *t_arr = (double*)malloc((n-1) * sizeof(double));
    for (i = 1; i < n; i++) {
        t_arr[i-1] = (double)i / ((double)n - 1.);
    }
    free(t_arr);
}
