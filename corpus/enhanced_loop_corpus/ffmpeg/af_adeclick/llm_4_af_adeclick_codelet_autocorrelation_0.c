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
        if (i >= size) continue;
        for (j = i; j < size; j++)
            value += input[j] * input[j - i];
        output[i] = value * scale;
    }
}
