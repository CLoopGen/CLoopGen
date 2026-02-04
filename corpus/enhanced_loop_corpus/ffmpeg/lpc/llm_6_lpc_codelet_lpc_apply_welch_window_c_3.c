#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_w;
    for (i = 0; i < n2; i++) {
        temp_w = c - n2 + i;
        temp_w = 1. - (temp_w * temp_w);
        w_data[-i - 1] = data[-i - 1] * temp_w;
        w_data[+i] = data[+i] * temp_w;
        w = temp_w; // Introduce WAW dependency: 'w' is written after use in computations
    }
}
