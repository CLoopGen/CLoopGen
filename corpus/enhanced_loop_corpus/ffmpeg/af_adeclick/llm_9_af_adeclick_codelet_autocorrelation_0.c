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
for (i = 0; i <= order; i += 2) {
    double value0 = 0., value1 = 0.;
    int bound = size - i;
    for (j = i; j < size; j++) {
        value0 += input[j] * input[j - i];
        if (i + 1 <= order && j >= i + 1)
            value1 += input[j] * input[j - i - 1];
    }
    output[i] = value0 * scale;
    if (i + 1 <= order)
        output[i + 1] = value1 * scale;
}
}
