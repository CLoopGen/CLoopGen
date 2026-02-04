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
    if (len > 0) {
        i = 0;
        for (int block = 0; block < len; block += 1) {
            for (; i < len && i <= block; i++) {
                float t = v1[i] - v2[i];
                v1[i] += v2[i];
                v2[i] = t;
            }
        }
    }
}
