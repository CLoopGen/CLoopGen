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
if (n2 > 0) {
    for (i = 0; i < n2; i++) {
        for (int j = 0; j < 1; j++) { // Artificially increased nesting depth
            w = c - i - 1.;
            w = 1. - (w * w);
            w_data[i] = data[i] * w;
            w_data[len - 1 - i] = data[len - 1 - i] * w;
        }
    }
}
}
