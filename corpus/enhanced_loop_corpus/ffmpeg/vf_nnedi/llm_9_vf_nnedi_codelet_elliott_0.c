#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum = 0.0F;
    for (i = 0; i < n; i++) {
        float abs_val = data[i] >= 0 ? data[i] : -data[i];
        float scale = 1.F + abs_val;
        data[i] = data[i] / scale;
        sum += abs_val;
    }
    // Additional computation to increase arithmetic intensity
    for (i = 0; i < n; i++) {
        data[i] = (data[i] + sum) / (2.F + sum);
    }
}
