#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *v1;
extern  float *v2;
extern int len;
extern float p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    p = 0.0f;
    for (i = 0; i < len; i++) {
        float prod = v1[i] * v2[i];
        if (prod > 0.0f) {
            p += prod;
        }
    }
}
