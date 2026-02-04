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
    for (i = 0; i < len; i++) {
        if (v1[i] == 0.0f || v2[i] == 0.0f) {
            continue;
        }
        p += v1[i] * v2[i];
    }
}
