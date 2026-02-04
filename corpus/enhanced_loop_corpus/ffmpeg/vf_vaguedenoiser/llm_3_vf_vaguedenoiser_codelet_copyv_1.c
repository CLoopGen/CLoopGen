#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *p1;
extern  int stride1;
extern float *p2;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *src = p1;
    for (i = 0; i < length; i++) {
        p2[i] = *(src + i * stride1);
    }
}
