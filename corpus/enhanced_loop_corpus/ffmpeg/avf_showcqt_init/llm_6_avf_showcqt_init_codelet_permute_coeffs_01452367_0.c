#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < len; k += 8) {
        float temp2 = v[k + 2];
        float temp3 = v[k + 3];
        float temp4 = v[k + 4];
        float temp5 = v[k + 5];

        v[k + 4] = temp2;
        v[k + 2] = temp4;

        v[k + 5] = temp3;
        v[k + 3] = temp5;
    }
}
