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
    if (order >= 0) {
        double value = 0.;
        for (j = 0; j < size; j++)
            value += input[j] * input[j];
        output[0] = value * scale;

        for (i = 1; i <= order; i++) {
            value = 0.;
            for (j = i; j < size; j++)
                value += input[j] * input[j - i];
            output[i] = value * scale;
        }
    }
}
