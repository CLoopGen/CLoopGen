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
for (i = 0; i < n2 / 2; i++) {
    double w1 = c - n2 + i;
    w1 = 1. - (w1 * w1);
    double w2 = c - n2 + n2 - i - 1;
    w2 = 1. - (w2 * w2);
    w_data[-i - 1] = data[-i - 1] * w1;
    w_data[+i] = data[+i] * w1;
    w_data[n2 - i - 1] = data[n2 - i - 1] * w2;
    w_data[-n2 + i] = data[-n2 + i] * w2;
}
}
