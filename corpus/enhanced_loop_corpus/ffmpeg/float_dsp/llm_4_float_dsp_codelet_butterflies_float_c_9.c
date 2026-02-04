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
for (i = 0; i < len; i++) {
    if (v1[i] >= v2[i]) {
        float t = v1[i] - v2[i];
        v1[i] += v2[i];
        v2[i] = t;
    } else {
        v1[i] += v2[i];
        v2[i] = v1[i] - 2 * v2[i];
    }
}
}
