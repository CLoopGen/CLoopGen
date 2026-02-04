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
    float local_scale = scalefactor * scalefactor;
    for (i = 0; i < n; i++) {
        out[i] = in[i] * local_scale + in[i] * (scalefactor - local_scale);
    }
}
