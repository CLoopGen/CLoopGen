#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern double *out;
extern  double *in;
extern integer len;
extern int i;
extern double coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (i % 2 == 0)
            out[i] = coeff * in[i];
        else
            out[i] = 0.0;
    }
}
