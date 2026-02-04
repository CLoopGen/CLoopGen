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
    for (i = j - 1; i < len; i += 2) {
        double prod1 = data[i] * data[i - j];
        double prod2 = data[i + 1] * data[i - j + 1];
        sum += prod1;
        sum += prod2; // Split the original combined operation to eliminate potential RAW hazard in fused expression
        data[i] = prod1; // Introduce WAW on data[i] — modifies memory location, creating new loop-carried dependence if j <= 2
    }
}
