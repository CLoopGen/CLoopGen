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
    // Variant 2: Reverse sequential access from end to start
    for (i = len - 1; i >= 0; i--)
        p += v1[i] * v2[i];
}
