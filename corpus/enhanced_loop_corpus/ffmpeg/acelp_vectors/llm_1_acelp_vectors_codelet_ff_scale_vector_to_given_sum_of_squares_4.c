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
    int j, k;
    for (j = 0; j < n; j += 2) {
        for (k = j; k < j + 2 && k < n; k++) {
            out[k] = in[k] * scalefactor;
        }
    }
}
