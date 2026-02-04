#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *a;
extern  float *b;
extern int length;
extern float sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to start
    for (i = length - 1; i >= 0; i--)
        sum += a[i] * b[i];
}
