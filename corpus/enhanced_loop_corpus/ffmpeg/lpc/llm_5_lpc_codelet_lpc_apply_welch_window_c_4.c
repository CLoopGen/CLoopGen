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
for (i = 0; i < n2 && len > 0; i++) {
    if (i < len) {
        w = c - i - 1.;
        w = 1. - (w * w);
        if (w > 0.5) {
            w_data[i] = data[i] * w;
            w_data[len - 1 - i] = data[len - 1 - i] * w;
        } else {
            w_data[i] = 0.0;
            w_data[len - 1 - i] = 0.0;
        }
    }
}
}
