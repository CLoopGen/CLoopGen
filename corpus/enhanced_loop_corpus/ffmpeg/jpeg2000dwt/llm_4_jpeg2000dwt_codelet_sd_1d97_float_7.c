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
    if (i0 >= i1) return;
    int start = i0 >> 1;
    int end = i1 >> 1;
    for (i = start; i < end; i++) {
        float temp = p[2 * i - 1] + p[2 * i + 1];
        p[2 * i] += 0.443506f * temp;
    }
}
