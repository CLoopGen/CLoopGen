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
    int start = (i0 >> 1) - 2;
    int end = (i1 >> 1) + 2;
    for (i = start; i < end; i += 2) {
        float temp1 = p[2 * i - 1] + p[2 * i + 1];
        float temp2 = 0.052979999999999999 * temp1;
        p[2 * i] -= temp2;
        if (i + 1 < end) {
            float temp3 = p[2 * (i + 1) - 1] + p[2 * (i + 1) + 1];
            p[2 * (i + 1)] -= 0.052979999999999999 * temp3;
        }
    }
}
