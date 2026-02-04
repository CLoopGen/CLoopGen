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
    int i;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            out[i] = in[i] * scalefactor;
            out[i+1] = in[i+1] * scalefactor;
        } else {
            out[i] = in[i] * scalefactor;
        }
    }
}
