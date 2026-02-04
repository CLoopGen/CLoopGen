#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *d = data;
    int j;
    for (j = 0; j < n; j++) {
        float val = d[j];
        float abs_val = val >= 0 ? val : -val;
        d[j] = val / (1.F + abs_val);
    }
}
