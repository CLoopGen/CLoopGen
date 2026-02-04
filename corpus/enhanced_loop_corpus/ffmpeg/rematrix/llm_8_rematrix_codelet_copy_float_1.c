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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i]     = coeff * in[i];
            out[i + 1] = coeff * in[i + 1];
        } else {
            out[i] = coeff * in[i];
        }
    }
}
