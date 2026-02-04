#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *restrict v1;
extern float *restrict v2;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        float t1 = v1[i] - v2[i];
        v1[i] += v2[i];
        v2[i] = t1;
        if (i + 1 < len) {
            float t2 = v1[i+1] - v2[i+1];
            v1[i+1] += v2[i+1];
            v2[i+1] = t2;
        }
    }
}
