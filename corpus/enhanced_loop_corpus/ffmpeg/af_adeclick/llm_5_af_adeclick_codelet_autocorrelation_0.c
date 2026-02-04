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
    for (i = 0; i <= order && size > 0; i++) {
        double value = 0.;
        for (j = i; j < size; j++) {
            if (input[j] == 0.0 || input[j - i] == 0.0) continue;
            value += input[j] * input[j - i];
        }
        output[i] = value * scale;
    }
}
