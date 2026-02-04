#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *input;
extern int order;
extern int size;
extern double *output;
extern double scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= order; i++) {
    double value = 0.;
    int step = 1;
    for (j = i; j < size; j += step) {
        int prev_idx = j - i;
        value += input[j] * input[prev_idx];
    }
    output[i] = value * scale;
}
}
