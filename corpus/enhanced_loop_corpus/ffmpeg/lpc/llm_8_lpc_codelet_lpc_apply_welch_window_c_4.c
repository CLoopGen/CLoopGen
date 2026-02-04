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
for (i = 0; i < n2; i += 2) {
    w = c - i - 1.;
    w = 1. - (w * w);
    w_data[i] = data[i] * w;
    w_data[len - 1 - i] = data[len - 1 - i] * w;
    if (i + 1 < n2) {
        double w2 = c - (i + 1) - 1.;
        w2 = 1. - (w2 * w2);
        w_data[i + 1] = data[i + 1] * w2;
        w_data[len - 1 - (i + 1)] = data[len - 1 - (i + 1)] * w2;
    }
}
}
