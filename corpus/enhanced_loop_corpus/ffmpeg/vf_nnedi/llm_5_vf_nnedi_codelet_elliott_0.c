#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        float abs_val = data[i] >= 0 ? data[i] : -data[i];
        float denominator = 1.F + abs_val;
        if (denominator > 1.0F) {
            data[i] = data[i] / denominator;
        } else {
            data[i] = 0.0F;
        }
    }
}
