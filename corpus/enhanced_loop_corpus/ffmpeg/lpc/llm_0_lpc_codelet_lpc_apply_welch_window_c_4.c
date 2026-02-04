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
    double w1, w2;
    int idx1 = i;
    int idx2 = i + 1;
    double w_val1 = c - idx1 - 1.;
    w_val1 = 1. - (w_val1 * w_val1);
    w1 = w_val1;
    w_data[idx1] = data[idx1] * w1;
    w_data[len - 1 - idx1] = data[len - 1 - idx1] * w1;

    if (idx2 < n2) {
        double w_val2 = c - idx2 - 1.;
        w_val2 = 1. - (w_val2 * w_val2);
        w2 = w_val2;
        w_data[idx2] = data[idx2] * w2;
        w_data[len - 1 - idx2] = data[len - 1 - idx2] * w2;
    }
}
}
