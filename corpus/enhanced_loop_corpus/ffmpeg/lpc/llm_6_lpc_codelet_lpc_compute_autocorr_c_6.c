#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int i;
extern int j;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = j - 1; i < len; i += 2) {
        temp_sum += data[i] * data[i - j];
        sum += temp_sum; // Introduces WAW dependency on 'sum' and loop-carried dependency via temp_sum accumulation
    }
    sum += temp_sum; // Final update outside loop to preserve partial semantics
}
