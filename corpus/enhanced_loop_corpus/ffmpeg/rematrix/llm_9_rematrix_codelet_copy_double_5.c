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
    double c_sq = coeff * coeff;
    for (i = 0; i < len; i++) {
        double temp = in[i] * in[i];
        out[i] = c_sq * temp + coeff * in[i];
    }
}
