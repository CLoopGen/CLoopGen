#include <stdio.h>

#include <inttypes.h>

extern double *in;
extern double *window;
extern int in_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    #pragma unroll
    for (j = 0; j < in_len; j += 2) {
        if (j + 1 < in_len) {
            in[j] *= window[j];           // Eliminate loop-carried dependency by processing independent elements
            in[j+1] *= window[j+1];       // Parallel updates with no cross-iteration dependencies
        } else {
            in[j] *= window[j];
        }
    }
}
