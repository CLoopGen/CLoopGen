#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  int n;
extern int i;
extern float scalefactor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i += 2) {
        out[i-1] = in[i-1] * scalefactor;
        out[i] = in[i] * scalefactor;
    }
    if (n % 2 == 1) {
        out[n-1] = in[n-1] * scalefactor;
    }
}
