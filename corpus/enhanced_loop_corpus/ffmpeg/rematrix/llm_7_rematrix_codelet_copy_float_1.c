#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in;
extern integer len;
extern int i;
extern float coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i++)
        out[i] = coeff * in[i-1];
    if (len > 0)
        out[0] = coeff * in[0];
}
