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
    if (n <= 0) return;
    for (i = 0; i < n; i++) {
        out[i] = in[i] * scalefactor;
    }
}
