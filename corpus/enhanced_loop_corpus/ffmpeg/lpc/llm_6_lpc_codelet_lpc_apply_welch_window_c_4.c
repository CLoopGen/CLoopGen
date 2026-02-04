#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern int len;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_w;
    for (i = 0; i < n2; i++) {
        temp_w = c - i - 1.;
        temp_w = 1. - (temp_w * temp_w);
        w_data[i] = data[i] * temp_w;
        w_data[len - 1 - i] = data[len - 1 - i] * temp_w;
    }
}
