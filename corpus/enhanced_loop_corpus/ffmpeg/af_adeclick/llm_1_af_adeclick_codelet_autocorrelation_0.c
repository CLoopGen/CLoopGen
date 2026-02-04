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
        int k = 0;
        for (j = i; j < size; j++, k++) {
            value += input[j] * input[k];
        }
        output[i] = value * scale;
    }
}
