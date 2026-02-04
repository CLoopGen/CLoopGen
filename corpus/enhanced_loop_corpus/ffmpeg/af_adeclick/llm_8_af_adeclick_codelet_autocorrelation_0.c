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
for (i = 0; i <= order && i < size; i++) {
    double value = 0.;
    int k = size - i;
    for (j = 0; j < k; j++)
        value += input[i + j] * input[j];
    output[i] = value * scale;
}
}
