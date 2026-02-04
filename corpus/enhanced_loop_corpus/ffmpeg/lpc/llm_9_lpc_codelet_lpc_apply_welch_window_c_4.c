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
for (i = 0; i < n2; i++) {
    double idx = (double)(c - i - 1.0);
    w = (1.0 - idx) * (1.0 + idx); // Equivalent to 1 - idx^2, reduced one operation via algebraic identity
    w_data[i] = (double)data[i] * w;
    int mirror_i = len - 1 - i;
    w_data[mirror_i] = (double)data[mirror_i] * w;
}
}
