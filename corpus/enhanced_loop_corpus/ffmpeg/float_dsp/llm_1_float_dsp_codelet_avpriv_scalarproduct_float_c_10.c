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
    if (len > 0) {
        i = 0;
        for (; i < len; i++) {
            p += v1[i] * v2[i];
        }
    }
}
