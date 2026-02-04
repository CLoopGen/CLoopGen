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
    float prev = 0.0F;
    for (j = 0; j < n; j++) {
        float curr = d[j];
        d[j] = curr / (1.F + ((curr) >= 0 ? (curr + prev) : -(curr)));
        prev = curr;
    }
}
