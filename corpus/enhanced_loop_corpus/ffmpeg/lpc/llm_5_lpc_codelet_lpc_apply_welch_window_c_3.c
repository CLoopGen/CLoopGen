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
for (i = 0; i < n2; i++) {
    if (i % 2 == 0) {
        w = c - n2 + i;
        w = 1. - (w * w);
    } else {
        w = 0.5;
    }
    w_data[-i - 1] = data[-i - 1] * w;
    w_data[+i] = data[+i] * w;
}
}
