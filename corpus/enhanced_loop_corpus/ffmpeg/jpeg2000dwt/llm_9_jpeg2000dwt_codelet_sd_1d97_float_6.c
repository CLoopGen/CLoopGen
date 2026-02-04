#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float coeff = 0.882911f * 2.0f;
    int stride = 4;
    int limit = (i1 >> 1) - 2;
    for (i = (i0 >> 1) + 1; i < limit; i += 2) {
        float temp1 = p[2*i] + p[2*i + 2];
        float temp2 = p[2*i - 2] + p[2*i];
        p[2*i + 1] += coeff * temp1;
        p[2*i - 1] += coeff * temp2;
    }
}
