#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern size_t ord;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ord <= 1) return;
    double *temp_arr = (double*)malloc(ord * sizeof(double));
    temp_arr[0] = l[1];
    for (i = 1; i < ord; i++) {
        temp_arr[i] = (ord + 1) * temp_arr[i - 1] / (i + 1);
    }
    for (i = 1; i < ord; i++) {
        l[i + 1] = temp_arr[i];
    }
    free(temp_arr);
}
