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
    double temp = 0.0;
    for (i = 0; i < len; i++) {
        temp = coeff * in[i];
        out[i] = temp;
    }
}
